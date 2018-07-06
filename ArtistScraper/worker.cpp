
/*
   Copyright 2013 Fabien Pierre-Nicolas.
      - Primarily authored by Fabien Pierre-Nicolas

   This file is part of simple-qt-thread-example, a simple example to demonstrate how to use threads.
   This example is explained on http://fabienpn.wordpress.com/qt-thread-simple-and-stable-with-sources/

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This progra is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "worker.h"
#include <QTimer>
#include <QEventLoop>

#include <QThread>
#include <QDebug>
#include "curleasy.h"
#include <QRegularExpressionMatchIterator>
#include <QTextDocumentFragment>
#include <QList>

Worker::Worker(QObject *parent) :
    QObject(parent)
{
    _working =false;
    _abort = false;
    params = "";
   // paramsPtr = &params;
    paramsPtr = new  QList <QString>();
    urlQueryParam = new QString();

}

Worker::~Worker()
{
  delete paramsPtr;
  delete urlQueryParam;
}

void Worker::requestWork()
{
    mutex.lock();
    _working = true;
    _abort = false;
    qDebug()<<"Request worker start in Thread "<<thread()->currentThreadId();
    mutex.unlock();

    emit workRequested();
}

void Worker::abort()
{
    mutex.lock();
    if (_working) {
        _abort = true;
        qDebug()<<"Request worker aborting in Thread "<<thread()->currentThreadId();
    }
    mutex.unlock();
}

void Worker::doWork()
{
    qDebug()<<"Starting worker process in Thread "<<thread()->currentThreadId();

    /**************
      We increment i 60 times
      Anytime i is increment we have a set interval that does something
      In our case scrape -- so every time I get incremented we have a scraping interval
      So we have to send a signal here to change the 60 to something else
    ************/
    //for (int i = 0; i < 60; i ++) {
    for (;;) {
        // Checks if the process should be aborted
        mutex.lock();
        bool abort = _abort;
        mutex.unlock();

        if (abort) {
            qDebug()<<"Aborting worker process in Thread "<<thread()->currentThreadId();
            break;
        }


        // This will stupidly wait 1 sec doing nothing...
        QEventLoop loop;
        QTimer::singleShot(6000, &loop, SLOT(quit()));
        loop.exec();

        // send signal to grab parameter options
        emit emitParameters();

        // send signal to show Keywords that are currently Queue
        emit emitKeywordQueue();


         //if url query that we recieved is not empty
        if(!urlQueryParam->isEmpty()){


            std::string url = urlQueryParam->toStdString();
            //std::string userAgent = paramsPtr->at(1).toStdString();


            CurlEasy *curl = new CurlEasy;
            curl->set(CURLOPT_URL, url.c_str());
            curl->set(CURLOPT_FOLLOWLOCATION, 1L); // Tells libcurl to follow HTTP 3xx redirects
            curl->set(CURLOPT_SSL_VERIFYPEER,FALSE);

            curl->perform();


            curl->setWriteFunction([this](char *data, size_t size)->size_t {



                //If response is not 200, obviously we wont get any emails,
                // but were only going to parse emails, only
                // so this means, we only get emails if::
                //1 reponse code is 200

                // qDebug() << "Data from google.com: " << QByteArray(data, static_cast<int>(size));
                QByteArray response(data,static_cast<int>(size));
                QString responseString = QString(response);

                QString plainText = QTextDocumentFragment::fromHtml( responseString).toPlainText();
                QString filteredNewLine = plainText.replace("\n"," ");
                QRegularExpression re("[a-z0-9]+[_a-z0-9.-]*[a-z0-9]+@[a-z0-9-]+(.[a-z0-9-]+)");
                QRegularExpressionMatchIterator i = re.globalMatch(filteredNewLine);
                QStringList words;
                QStringList test;
                QString word;
                QRegularExpressionMatch match;
                QList<QString> list;
                QString emailList;
                int num = 0;

                while (i.hasNext()) {
                    QRegularExpressionMatch match = i.next();
                      if(!match.captured(0).isEmpty())
                          word = match.captured(0);
                      //words << word;
                     //MainWindow::emails = &words;
                     if(!word.isEmpty()){
                         words << word;
                        // emailList = words.at(num);
                         list << words;
                         emit emitEmailList(words.at(num));

                            num++;

                     } // end words !empty

                } // end while



                return size;
            });// end setWriteFunction

            connect(curl, &CurlEasy::done, [curl](CURLcode result) {
                long httpResponseCode = curl->get<long>(CURLINFO_RESPONSE_CODE);

                QString effectiveUrl = curl->get<const char*>(CURLINFO_EFFECTIVE_URL);

                /*********HTTP CODE*******/
                // Log errors,or show message to user if response code is not 200
                if(httpResponseCode == 200 && result ==CURLE_OK){

                   //qDebug() << "GOOD TO SCRAPE";
                }else{
                    qDebug() << "Error HTTP CODE--->" <<  httpResponseCode;
                }

                if(result != result){
                    qDebug() << "CURLcode is NOT OK :: result is--->" << result;
                    qDebug() << "CURLcode is NOT OK :: HTTP CODE--->" << httpResponseCode;
                }

            }); // end curl connect


            connect(curl, SIGNAL(done(CURLcode)),curl, SLOT(deleteLater()));


        } //if paramsPtr is empty set of an error, shut down program, or let user know???
          // but this shouldnt happen because important options/parameters will always
          // bet set by default.
        else{
           // EXIT_FAILURE;
        } // end if for checking paramsPtr



        // Once we're done waiting, value is updated
        emit valueChanged(QString::number(1));
    }

    // Set _working to false, meaning the process can't be aborted anymore.
    mutex.lock();
    _working = false;
    mutex.unlock();

    qDebug()<<"Worker process finished in Thread "<<thread()->currentThreadId();

    //Once 60 sec passed, the finished signal is sent
    emit finished();
}

void Worker::getParam(QString url,QString userAgent)
{
    *urlQueryParam = url;

}

void Worker::getProxyFile(QString fileName)
{
    //qDebug() << "Received proxy file name" << fileName ;
}
