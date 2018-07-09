#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHeaderView>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include "options.h"
#include <QUrl>
#include <QToolTip>
#include <QEvent>
#include <QMouseEvent>
#include <QHash>
#include <QVector>
#include <memory>
#include <string>
#include <cstdio>
#include <QTextDocumentFragment>
#include <QList>
#include <QModelIndex>
#include <stdio.h>
#include <string.h>






QStringList* MainWindow::emails;
QString* MainWindow::fetchWriteCallBackCurlData;


MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)

{

     ui->setupUi(this);

     QSize size = this->size();
     this->setFixedSize(size);
     setSearchResults();
     setProxyTable();
     //setEmailTable();
     setWindowTitle("Beat Crawler V0.1.9 (C) Beatcrawler.com");
     ui->lineEdit_keywords_search_box->setPlaceholderText("my mixtape");
     fetchWriteCallBackCurlDataString = "";
     MainWindow::fetchWriteCallBackCurlData = &fetchWriteCallBackCurlDataString;

     // The thread and the worker are created in the constructor so it is always safe to delete them.
     thread = new QThread();
     worker = new Worker();
     worker->moveToThread(thread);
    // connect(worker, SIGNAL(valueChanged(QString)), ui->label, SLOT(setText(QString)));
     connect(worker, SIGNAL(workRequested()), thread, SLOT(start()));
     connect(thread, SIGNAL(started()), worker, SLOT(doWork()));
     connect(worker, SIGNAL(finished()), thread, SLOT(quit()), Qt::DirectConnection);
     connect(worker,SIGNAL(emitParameters()),this,SLOT(receiverParameters()));
     connect(this,SIGNAL(postParam(QString,QString,QList <QString> *)),worker,SLOT(getParam(QString,QString,QList <QString> *)));
     connect(worker,SIGNAL(emitEmailList(QString)),this,SLOT(receiverEmailList(QString)));
     connect(this,SIGNAL(emitsenderEmptyProxyServer(QString)),worker,SLOT(receiverEmptyProxyServer(QString)));
     connect(this,SIGNAL(emitsenderStopThreadCounters(QString)),worker,SLOT(receiverStopThreadCounters(QString)));
     connect(this,SIGNAL(emitsenderStartThreadCounters(QString)),worker,SLOT(receiverStartThreadCounters(QString)));
     connect(worker,SIGNAL(senderCurlResponseInfo(QString)),this,SLOT(recieverCurlResponseInfo(QString)));

     //connect(this,SIGNAL(senderOpenProxyFlile(QString)),worker,SLOT(getProxyFile(QString)));
     // delete selected proxy row

     connect(ui->tableWidget_Proxy->selectionModel(),
             SIGNAL(selectionChanged(const QItemSelection & , const QItemSelection & )),this,
             SLOT(recieverProxyTableSelection(const QItemSelection &,const QItemSelection &)));
     emailList = new QList <QString>();
    // setEmailList = new QList <QString>();

     proxyServers = new QList <QString>();
     connect(worker,SIGNAL(emitKeywordQueue()),this,SLOT(recieverKeywordsQueue()));
     options = new OptionsPtr[numOptions];
     for (int i = 0; i < numOptions; i++) {
         options[i] = new Options();
     }
    proxyList = new QStringList[1];

    // ui->lineEdit_keywords_search_box->installEventFilter(this);

     QStringList emailTableHeaders;
     emailTableHeaders  << "Emails";
     ui->tableWidget_Emails->setRowCount(60000);
     ui->tableWidget_Emails->setColumnCount(1);

     ui->tableWidget_Emails->setHorizontalHeaderLabels(emailTableHeaders);
     ui->tableWidget_Emails->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     ui->tableWidget_Emails->resizeRowsToContents();

     ui->tableWidget_Proxy->setSelectionBehavior(QAbstractItemView::SelectRows);

     ui->pushButton_Start->setCheckable(true);
     ui->checkBox_Bing->setChecked(true);
     ui->checkBox_Email_Gmail->setChecked(true);
     ui->checkBox_Email_Hotmail->setChecked(true);
     ui->checkBox_Email_Yahoo->setChecked(true);
     ui->checkBox_Google->setChecked(true);
     ui->checkBox_Social_Facebook->setChecked(true);
     ui->checkBox_Social_Instagram->setChecked(true);
     ui->checkBox_Social_Myspace->setChecked(true);
     ui->checkBox_Social_Reverbnation->setChecked(true);
     ui->checkBox_Social_Soundcloud->setChecked(true);
     ui->checkBox_Yahoo->setChecked(true);
     ui->radioButton_Android_Webkit->setChecked(true);

     ui->pushButton_Next_Email_Pagination->hide();
     ui->pushButton_Previous_Email_Pagination->hide();
     ui->lineEdit_Keyword_List_File_Location->setEnabled(false);


    emailOptionsNum = 0 ;
    searchEngineNum =0;
    socialNetWorkNum =0;
    keywordLoadListOptionsNum =0;
    searchEngineNumPtrAddedBool = false;
    searchEngineNumPtrNum =0;
    currentKeyword = "";

    // increments search engine pagination query on each interval

    keywordSearchBoxSearchEngineCounterNum = 0;
    keywordListSearchEngineCounterNum =0;


    keywordSearchBoxSearchEngineCounterPtr = &keywordSearchBoxSearchEngineCounterNum;
    keywordListSearchEngineCounterPtr = &keywordListSearchEngineCounterNum;

    emailOptionsNumPtr = &emailOptionsNum;
    searchEngineNumPtr = &searchEngineNum;
    socialNetWorkNumPtr = &socialNetWorkNum;


    keywordLoadListOptionsNumPtr = &keywordLoadListOptionsNum;
    searchEngineNumPtrAdded = &searchEngineNumPtrAddedBool;
    searchEngineNumPtrCounter = &searchEngineNumPtrNum;
    currentKeywordPtr = &currentKeyword;

    keywordBoxNumPtrNum = 0;
    keywordBoxNumPtrCounter = &keywordBoxNumPtrNum;

    keywordListNumPtrNum = 0;
    keywordListNumPtrCounter = &keywordListNumPtrNum;

    nextEmailPagination = 20;
    nextEmailPaginationPtr = &nextEmailPagination;

    previousEmailPagination = 0;
    previousEmailPaginationPtr = &previousEmailPagination;

    addProxyCounterNum = 0;
    addProxyCounterPtr = &addProxyCounterNum;


    // put inside method
    for(int j =0;  j < ui->tableWidget_Emails->rowCount();  j ++)
    {
            ui->tableWidget_Emails->hideRow(j);
    }



}



MainWindow::~MainWindow()

{

    delete ui;
    delete options;
    delete proxyList;
    delete proxyModelTable;
    delete emailModelTable;

    worker->abort();
    thread->wait();
    qDebug()<<"Deleting thread and worker in Thread "<<this->QObject::thread()->currentThreadId();
    delete thread;
    delete worker;
    delete emailList;
    //delete setEmailList;
    delete ui;
    delete proxyServers;

}







void MainWindow::setProxyTable(){

}


void MainWindow::setSearchResults(){
    //search engine results
    for(int i =1000; i >=1; i--)
    {
       QString s = QString::number(i);
       ui->comboBox_search_results_amount->addItem(s);
    }

}


void MainWindow::on_pushButton_Start_clicked(bool checked)

{
    QStringList keywordQueueTableHeaders;
    if(checked){

        //check if main options are empty, our program is based around these important options
        // at least one has to be checked. (These will be empty arrays, if at least one isnt checked!)
        if(!ui->checkBox_Google->isChecked() && !ui->checkBox_Yahoo->isChecked() &&
                !ui->checkBox_Bing->isChecked())
        {

            QMessageBox::information(this,"...","Please select at least one search engine option");
            isSearchEngineSelectOne = false;
        }

        else
        {
            isSearchEngineSelectOne = true;
        }


        if(!ui->checkBox_Social_Instagram->isChecked() && !ui->checkBox_Social_Facebook->isChecked()
         && !ui->checkBox_Social_Soundcloud->isChecked() && !ui->checkBox_Social_Reverbnation->isChecked()
         &&! ui->checkBox_Social_Myspace->isChecked())
        {
            QMessageBox::information(this,"...","Please select at least one social network option");
            isSocialNetworkSelectOne = false;
        }

        else
        {
             isSocialNetworkSelectOne = true;
        }

        if(!ui->checkBox_Email_Gmail->isChecked() && !ui->checkBox_Email_Hotmail->isChecked()
         && !ui->checkBox_Email_Yahoo->isChecked() )

        {

            QMessageBox::information(this,"...","Please select at least one email option");
            isEmailSelectOne = false;
        }

        else{
             isEmailSelectOne = true;
        }

         //if we press start buttonand keyword searchb box and keyword list hasnt beeen choosen
        if(ui->lineEdit_keywords_search_box->text().isEmpty() && options[4]->keywordLoadListOptions.isEmpty())
        {
            QMessageBox::information(this,"...","Please enter a keyword, or Load a list of keywords");
            isKeywordsSelect = false;
        }

        else
        {
             isKeywordsSelect = true;
        }

        // search box is empty but we keywords in list // ok
        if(ui->lineEdit_keywords_search_box->text().isEmpty() && !options[4]->keywordLoadListOptions.isEmpty())
        {
            isKeywordsSelect = true;
        }

        // search box is  not empty but we dont have keywords in list // ok
        if(!ui->lineEdit_keywords_search_box->text().isEmpty() && options[4]->keywordLoadListOptions.isEmpty()){
            isKeywordsSelect = true;
        }


        if(isSocialNetworkSelectOne==true &&   isSearchEngineSelectOne ==true && isKeywordsSelect ==true
          && isEmailSelectOne == true)
        {

            ui->pushButton_Start->setText("Stop");

            // if keyword list is not empty, and keywordsearch box isnt empty add
            // the keyword from search box into keyword list hash table
            if(!ui->lineEdit_keywords_search_box->text().isEmpty() && !options[4]->keywordLoadListOptions.isEmpty())
            {
               options[4]->keywordLoadListOptions.insert(ui->lineEdit_keywords_search_box->text(),0);


            }
             // clears emails queue table if any emails were in it
            keywordQueueTableHeaders  << "Keywords" << "Status";
            ui->tableWidget_Keywords_Queue->setHorizontalHeaderLabels(keywordQueueTableHeaders);


            // KEYWORD BOX INPUT
            if(!ui->lineEdit_keywords_search_box->text().isEmpty())
            {
                QMessageBox msgBox;
                QString cleanString = ui->lineEdit_keywords_search_box->text();

               // QString filteredString1 = cleanString.remove(QRegExp(QString::fromUtf8("[^\S+(\s\S+)+$]")));
                // creates a array from string
                //QStringList filteredString2 = filteredString1.split(" ");
                options[3]->keywordSearchBoxOptions[0] = cleanString;

            }


            //SEARCH ENGINE OPTION
            if(ui->checkBox_Google->isChecked())
            {
                options[0]->searchEngineOptions[0] ="http://google.com";
            }

            if(ui->checkBox_Bing->isChecked())
            {
                options[0]->searchEngineOptions[1] ="http://bing.com";
            }

            if(ui->checkBox_Yahoo->isChecked())
            {
                options[0]->searchEngineOptions[2] ="http://yahoo.com";
            }

            //EMAIL OPTION
            if(ui->checkBox_Email_Gmail->isChecked()){

               options[1]->emailOptions[0] = "@gmail.com";

            }

            if(ui->checkBox_Email_Yahoo->isChecked()){

                options[1]->emailOptions[1] = "@yahoo.com";

            }

            if(ui->checkBox_Email_Hotmail->isChecked()){

                options[1]->emailOptions[2] = "@hotmail.com";

            }



            //SOCIAL NETWORK OPTION

            if(ui->checkBox_Social_Instagram->isChecked()){

               options[2]->socialNetworkOptions[0] ="site:instagram.com";

            }

            if(ui->checkBox_Social_Facebook->isChecked()){

                 options[2]->socialNetworkOptions[1] ="site:facebook.com";

            }

            if(ui->checkBox_Social_Soundcloud->isChecked()){

                options[2]->socialNetworkOptions[2] ="site:soundcloud.com";

            }



            if(ui->checkBox_Social_Reverbnation->isChecked()){

               options[2]->socialNetworkOptions[3] ="site:reverbnation.com";

            }



            if(ui->checkBox_Social_Myspace->isChecked()){

                options[2]->socialNetworkOptions[4] ="site:myspace.com";

            }



            //USER AGENT OPTIONS

            if(ui->radioButton_Android_Webkit->isChecked()){

                options[5]->userAgentsOptions[0] = "Mozilla/5.0 (Linux; U; Android 4.0.3; ko-kr; LG-L160L Build/IML74K) AppleWebkit/534.30 (KHTML, like Gecko) Version/4.0 Mobile Safari/534.30";

            }



            if(ui->radioButton_Blackberry->isChecked()){

                options[5]->userAgentsOptions[0] = "Mozilla/5.0 (BlackBerry; U; BlackBerry 9900; en) AppleWebKit/534.11+ (KHTML, like Gecko) Version/7.1.0.346 Mobile Safari/534.11+";

            }



            if(ui->radioButton_IE_Mobile->isChecked()){

                options[5]->userAgentsOptions[0] = "Mozilla/5.0 (compatible; MSIE 9.0; Windows Phone OS 7.5; Trident/5.0; IEMobile/9.0)";

            }





            //SEARCH RESULTS COMBO BOX

            if(!ui->comboBox_search_results_amount->currentText().isEmpty()){

                // ui->comboBox_search_results_amount->currentText()

            }





            // To avoid having two threads running simultaneously, the previous thread is aborted.
            worker->abort();
            // If the thread is not running, this will immediately return.
            thread->wait();
            worker->requestWork();
            emit emitsenderStartThreadCounters("Start");
            ui->label_Curl_Status->setText("Status: Starting...");
            clickedStartStopButton = true;
            //disables options, stops user from altering options while harvesting
            ui->tabWidget_Harvester_Options->setEnabled(false);
           // ui->tabWidget_Global->setTabEnabled(3,false);
            ui->tableWidget_Proxy->setEnabled(false);
            ui->lineEdit_Proxy_Host->setEnabled(false);
            ui->lineEdit_Proxy_Port->setEnabled(false);
            ui->pushButton_Add_Proxy->setEnabled(false);


        }

    } // end if checked



    if(!checked){


        worker->abort();
        thread->quit();
        emit emitsenderStopThreadCounters("Stop");
        ui->label_Curl_Status->setText("Status: ");
        clickedStartStopButton = false;
        ui->pushButton_Start->setText("Start");
        *searchEngineNumPtr=0;
        *searchEngineNumPtrCounter=0;
        *keywordSearchBoxSearchEngineCounterPtr =0;
        *keywordListSearchEngineCounterPtr = 0;
        *keywordListNumPtrCounter = 0;
        *keywordBoxNumPtrCounter =0;
        ui->tabWidget_Harvester_Options->setEnabled(true);
       // ui->tabWidget_Global->setTabEnabled(3,true);
        ui->tableWidget_Proxy->setEnabled(true);
        ui->lineEdit_Proxy_Host->setEnabled(true);
        ui->lineEdit_Proxy_Port->setEnabled(true);
        ui->pushButton_Add_Proxy->setEnabled(true);






         for(int i =0; i <vectorSocialNetworks2.size(); i++){

             // of we need the string, pass in at() which returns the string

                  //vectorSocialNetworks2.remove(*vectorSocialNetworks2.at(i));

                 //qDebug() << vectorSocialNetworks2;

            // qDebug() << (vectorSocialNetworks2.at(i));

         }



    }



}



void::MainWindow::getKeywordsSearchBoxOrList(){

    //changeBool = true;

    //startScrape = &changeBool;

    if(*startScrape){



    }else{

        qDebug() << "Not Scraping";

    }

}







void MainWindow::on_pushButton_Load_Keyword_List_clicked()

{
    //ui->lineEdit_keywords_search_box->setEnabled(false);
    //ui->pushButton_Load_Keyword_List->setEnabled(true);
   // ui->lineEdit_keywords_search_box->setText("");
    ui->tableWidget_Keywords_Queue->clear();
    ui->tableWidget_Keywords_Queue->setRowCount(0);
    ui->tableWidget_Keywords_Queue->setColumnCount(0);
    options[4]->keywordLoadListOptions.clear();
    QString fileName = QFileDialog::getOpenFileName(this,"Open text file","C://");
    QFile file(fileName);
    QString filteredString1;
    QString filteredString2;
    QStringList filteredString3;
    QHash<QString,int>hashKeywordLoadList;

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       //QMessageBox::warning(this,"...","error in opening text file");
       // return;
    }

     QFileInfo fi(file.fileName());
     QString fileExt = fi.completeSuffix();

     if(fileExt == "txt"){
         ui->lineEdit_Keyword_List_File_Location->setText(file.fileName());
         while(!file.atEnd())
         {
             filteredString1.append(file.readLine());
             //filteredString2 = filteredString1.remove(QRegExp(QString::fromUtf8("[^A-Za-z0-9 ]")));
             filteredString3 = filteredString1.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
             for(int i = 0; i <filteredString3.size(); i++ )
             {
                 options[4]->keywordLoadListOptions[filteredString3.at(i)] =0;
             }

          }
     }

     else
     {
         QMessageBox::warning(this,"...","Please select a text file");
     }

      file.close();
}




void MainWindow::setEmailTable()

{

}

bool MainWindow::eventFilter(QObject *watched,QEvent *event){

    if(watched == ui->lineEdit_keywords_search_box && event->type() == QEvent::MouseButtonPress){

        /*******
         if we enter keywords in keyword search box, disable keyword load list button
       *****/
         //ui->lineEdit_keywords_search_box->setEnabled(true);
        // ui->pushButton_Load_Keyword_List->setEnabled(false);

         return true;
    }

    return false;

}





void MainWindow::mousePressEvent(QMouseEvent *event){

    //    if we click left button, enable both keyword load list button, and keyword search box
    if(event->button() ==Qt::LeftButton)

        {
        // ui->lineEdit_keywords_search_box->setEnabled(true);
         //ui->pushButton_Load_Keyword_List->setEnabled(true);

        }

}




//QVector<QString> * MainWindow::returnCurlData(QString *url,QString *userAgent){

//    vector->prepend(*url);

//    vector->prepend(*userAgent);

//    qDebug() << vector->size();

//    return vector;



//}





void MainWindow::receiverParameters()

{

    QString curlParam;
    QString searchEngineParam;
    QString castSearchQueryNumPtr;
    QString socialNetWork;
    QString email;
    QString searchEngine;
    QString vectorSearchEngineOptionsLastItem;
    QString currentKeywordSearchBoxKeyword;
    QString filterCurrentKeyword;






               /******

                  Loops through keyword list, and gets key, and value.

                  Remember were tagging each keyword of being busy 1, or not busy 0

                  If keyword is busy we move increment i++ to get the next keword in list

                  to check its tagged status.

              ****/

               QHash<QString, int>::const_iterator i = options[4]->keywordLoadListOptions.constBegin();



               //qDebug() << options[4]->keywordLoadListOptions

               while (i != options[4]->keywordLoadListOptions.constEnd()) {

                   // Keyword is good to use,

                   if(i ==i && i.value() == 0){

                       *currentKeywordPtr = i.key();

                       break;



                   }else{

                       // ONLY INCREMENT ITERATOR ON CERTAIN CONDITION BELOW

                       // Keyword is not good to use, increment keyword index, go to next keyword to scrape

                       i++;

                   }

               }


              // ui->label_Current_Keyword->setText("Current Keyword: " + *currentKeywordPtr);

               (*keywordListNumPtrCounter)+=1;



               /**********Search Engine Options ******/





                              /*******Email Options******/

                              vectorSearchEngineOptions.clear();

                              for(int i =0; i < vectorSearchEngineOptions.size(); i++){

                                      vectorSearchEngineOptions.removeAll(vectorSearchEngineOptions.at(i));



                              }





                              if(ui->checkBox_Google->isChecked()){

                                   vectorSearchEngineOptions.resize(1);

                                   vectorSearchEngineOptions.push_back(options[0]->searchEngineOptions[0]);





                                }



                              if(ui->checkBox_Bing->isChecked()){

                                    vectorSearchEngineOptions.resize(2);

                                    vectorSearchEngineOptions.push_back(options[0]->searchEngineOptions[1]);

                               }



                              if(ui->checkBox_Yahoo->isChecked()){

                                    vectorSearchEngineOptions.resize(3);

                                    vectorSearchEngineOptions.push_back(options[0]->searchEngineOptions[2]);

                               }





                              // removes empty index

                              for(int i =0; i < vectorSearchEngineOptions.size(); i++){

                                        vectorSearchEngineOptions.removeAll("");



                              }



                              if(vectorSearchEngineOptions.size()  == *searchEngineNumPtr){

                                     *searchEngineNumPtr=0; // done



                              }

                              if(vectorSearchEngineOptions.contains(vectorSearchEngineOptions.at(*searchEngineNumPtr))){

                                     searchEngine =  vectorSearchEngineOptions.at(*searchEngineNumPtr);

                              }









                              /********End Search Engine Options*****/



               //  if(searchEngine == "http://google.com" ){



               if(searchEngine == "http://google.com" ){





                   /*******Email Options******/

                   vectorEmailOptions.clear();

                   for(int i =0; i < vectorEmailOptions.size(); i++){

                           vectorEmailOptions.removeAll(vectorEmailOptions.at(i));



                   }





                   if(ui->checkBox_Email_Gmail->isChecked()){

                       vectorEmailOptions.resize(1);

                       vectorEmailOptions.push_back(options[1]->emailOptions[0]);





                     }



                   if(ui->checkBox_Email_Yahoo->isChecked()){

                       vectorEmailOptions.resize(2);

                       vectorEmailOptions.push_back(options[1]->emailOptions[1]);

                    }



                   if(ui->checkBox_Email_Hotmail->isChecked()){

                        vectorEmailOptions.resize(3);

                        vectorEmailOptions.push_back(options[1]->emailOptions[2]);

                    }





                   // removes empty index

                   for(int i =0; i <vectorEmailOptions.size(); i++){

                            vectorEmailOptions.removeAll("");



                   }





                   if(vectorEmailOptions.size()  == *emailOptionsNumPtr){

                          *emailOptionsNumPtr=0; // done



                   }

                   if(vectorEmailOptions.contains(vectorEmailOptions.at(*emailOptionsNumPtr))){

                          email =  vectorEmailOptions.at(*emailOptionsNumPtr);

                   }



                   /*****Email Section done****/







                   // clears vector, if not we will keep resizing the vector on each timer

                   vectorSocialNetworks2.clear();

                   for(int i =0; i <vectorSocialNetworks2.size(); i++){

                            vectorSocialNetworks2.removeAll(vectorSocialNetworks2.at(i));



                   }





                   if(ui->checkBox_Social_Instagram->isChecked()){

                       vectorSocialNetworks2.resize(1);

                       vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[0]);





                     }



                   if(ui->checkBox_Social_Facebook->isChecked()){

                       vectorSocialNetworks2.resize(2);

                       vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[1]);

                    }



                   if(ui->checkBox_Social_Soundcloud->isChecked()){

                        vectorSocialNetworks2.resize(3);

                        vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[2]);

                    }



                   if(ui->checkBox_Social_Reverbnation->isChecked()){

                        vectorSocialNetworks2.resize(4);

                        vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[3]);

                    }



                   if(ui->checkBox_Social_Myspace->isChecked()){

                        vectorSocialNetworks2.resize(5);

                        vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[4]);

                    }



                   // removes empty index

                   for(int i =0; i <vectorSocialNetworks2.size(); i++){

                            vectorSocialNetworks2.removeAll("");



                   }







                   if(vectorSocialNetworks2.size()  == *socialNetWorkNumPtr){

                          *socialNetWorkNumPtr=0; // done



                   }

                   if(vectorSocialNetworks2.contains(vectorSocialNetworks2.at(*socialNetWorkNumPtr))){

                          socialNetWork =  vectorSocialNetworks2.at(*socialNetWorkNumPtr);

                   }







                   (*keywordListSearchEngineCounterPtr)+=10;

                   /*****Cast num to string to put inside query string******/

                   castSearchQueryNumPtr = QString::number(*keywordListSearchEngineCounterPtr);


                   /**********
                   if search box is not empty assign search box value to currentKeywordSearchBoxKeyword
                   so incase keywordLoadListOptions is empty, we can allow it be appended to searchEngineParam
                   on its own.

                   --->>> If both keywordLoadListOptions, and searchbox keyword is NOT empty,
                   were going to add the search bpx keyword to the keywordLoadListOptions Hash Table
                   to be included for processing.

                   ************/
                   if(!ui->lineEdit_keywords_search_box->text().isEmpty())
                   {


                       currentKeywordSearchBoxKeyword = options[3]->keywordSearchBoxOptions[0];
                       ui->label_Current_Keyword->setText("Current Keyword: " + currentKeywordSearchBoxKeyword);

                       searchEngineParam = "https://www.google.com/search?q=" +socialNetWork +"%20"
                              +email+ "%20" + currentKeywordSearchBoxKeyword.replace(" ","+") +
                               "&ei=yv8oW8TYCOaN5wKImJ2YBQ&start=" + castSearchQueryNumPtr +"&sa=N&biw=1366&bih=613";

                   }



                   if(!options[4]->keywordLoadListOptions.empty())
                   {

                       ui->label_Current_Keyword->setText("Current Keyword: " +  currentKeywordPtr->replace("+"," "));
                       searchEngineParam = "https://www.google.com/search?q=" +socialNetWork +"%20"
                              +email+ "%20" + currentKeywordPtr->replace(" ","+") +
                               "&ei=yv8oW8TYCOaN5wKImJ2YBQ&start=" + castSearchQueryNumPtr +"&sa=N&biw=1366&bih=613";


                   }



                   // if both are not empty used currentKeywordPtr because the searchbox keyword is in the
                   // qlist/hash and will be eventuall processed
                   if(!options[4]->keywordLoadListOptions.empty() && !ui->lineEdit_keywords_search_box->text().isEmpty())
                   {
                       ui->label_Current_Keyword->setText("Current Keyword: " +  currentKeywordPtr->replace("+"," "));


                   }




                       /****Continues email quene***/

                       if(*keywordListSearchEngineCounterPtr  == 100){

                           if(*emailOptionsNumPtr <=   vectorEmailOptions.size()  ){

                                (*emailOptionsNumPtr)+=1;



                             }

                       }







                       /****Continues social network quene***/

                       if(*keywordListSearchEngineCounterPtr  == 100){

                           if(*socialNetWorkNumPtr <=   vectorSocialNetworks2.size()  ){

                               (*socialNetWorkNumPtr)+=1;



                             }

                       }









                       /*******Stops social network quene, and moves on to next******/

                       if(*keywordListSearchEngineCounterPtr  == 100){

                          *keywordListSearchEngineCounterPtr = 0;



                           // if social network pointer, and email options pointer is

                           //than the size of  socialNetworkOptions arrary,

                           //then were done, and move on

                           if(*socialNetWorkNumPtr ==  vectorSocialNetworks2.size()){

                               //(*socialNetWorkNumPtr)+=0;

                              //(*socialNetWorkNumPtr)+=1; //

                               //qDebug() << "MOVE ON";

                               // add one to it if theres a element before it

                               //vectorSocialNetwork   get current el, check to see if theres a el after it, then

                               // increment it

                              // (*searchEngineNumPtr)+=1;

                              // vectorSearchEngineOptions.at(*searchEngineNumPtr)



                               // if the last item in vector is true, and dosent match our current value

                               // theres more elements after our current element, we need

                               // this to make sure out pointer dosent get out of a range/QVector out of range.



                               if(!vectorSearchEngineOptions.last().isEmpty()){

                                   vectorSearchEngineOptionsLastItem = vectorSearchEngineOptions.last();

                                   if( vectorSearchEngineOptionsLastItem !=  vectorSearchEngineOptions.at(*searchEngineNumPtr) ){

                                               (*searchEngineNumPtr)+=1;

                                   }

                               }



                               if(vectorSearchEngineOptions.size()  == *searchEngineNumPtr){

                                     // *searchEngineNumPtr+=1; // done



                               }

                               /****Continues search engine quene***/

                              // (*searchEngineNumPtr )+=1; // this should only be used when were done scraping





                               /****Continues search engine quene***/

                              if(*keywordListSearchEngineCounterPtr == 100){

                                  // cant use above condition because were resetting

                                  //*keywordListSearchEngineCounterPtr to 0

                                    // (*searchEngineNumPtr )+=1; // this should only be used when were done scraping

                              }



                               /*****

                                 // MOVE ON TO NEXT

                                 //

                                 if next checkbox option is not checked skip it/add two two pointer

                                 by incrementing pointer by 2 we skip the checkbox option thats empty,

                                 and go to the next one, else dont skip it, and go to it --> increment by 1

                               *****/



//                               if(!ui->checkBox_Bing->isChecked()){

//                                      (*searchEngineNumPtr)+=2;

//                               }

//                               if(ui->checkBox_Bing->isChecked()){

//                                      (*searchEngineNumPtr)+=1;

//                               }



                           }



                           if( *emailOptionsNumPtr > vectorEmailOptions.size()){

                               *emailOptionsNumPtr=0;

                           }

                       }





                      //qDebug() << searchEngineParam;

                     // qDebug()<<  searchEngine;

                     // qDebug()<<  vectorSearchEngineOptions;

                     // qDebug() << *keywordListSearchEngineCounterPtr;

                 }











               /********Bing********/

               if(searchEngine == "http://bing.com" ){







                   /*******Email Options******/

                   vectorEmailOptions.clear();

                   for(int i =0; i < vectorEmailOptions.size(); i++){

                           vectorEmailOptions.removeAll(vectorEmailOptions.at(i));



                   }





                   if(ui->checkBox_Email_Gmail->isChecked()){

                       vectorEmailOptions.resize(1);

                       vectorEmailOptions.push_back(options[1]->emailOptions[0]);





                     }



                   if(ui->checkBox_Email_Yahoo->isChecked()){

                       vectorEmailOptions.resize(2);

                       vectorEmailOptions.push_back(options[1]->emailOptions[1]);

                    }



                   if(ui->checkBox_Email_Hotmail->isChecked()){

                        vectorEmailOptions.resize(3);

                        vectorEmailOptions.push_back(options[1]->emailOptions[2]);

                    }





                   // removes empty index

                   for(int i =0; i <vectorEmailOptions.size(); i++){

                            vectorEmailOptions.removeAll("");



                   }





                   if(vectorEmailOptions.size()  == *emailOptionsNumPtr){

                          *emailOptionsNumPtr=0; // done



                   }

                   if(vectorEmailOptions.contains(vectorEmailOptions.at(*emailOptionsNumPtr))){

                          email =  vectorEmailOptions.at(*emailOptionsNumPtr);

                   }



                   /*****Email Section done****/







                   // clears vector, if not we will keep resizing the vector on each timer

                   vectorSocialNetworks2.clear();

                   for(int i =0; i <vectorSocialNetworks2.size(); i++){

                            vectorSocialNetworks2.removeAll(vectorSocialNetworks2.at(i));



                   }





                   if(ui->checkBox_Social_Instagram->isChecked()){

                       vectorSocialNetworks2.resize(1);

                       vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[0]);





                     }



                   if(ui->checkBox_Social_Facebook->isChecked()){

                       vectorSocialNetworks2.resize(2);

                       vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[1]);

                    }



                   if(ui->checkBox_Social_Soundcloud->isChecked()){

                        vectorSocialNetworks2.resize(3);

                        vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[2]);

                    }



                   if(ui->checkBox_Social_Reverbnation->isChecked()){

                        vectorSocialNetworks2.resize(4);

                        vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[3]);

                    }



                   if(ui->checkBox_Social_Myspace->isChecked()){

                        vectorSocialNetworks2.resize(5);

                        vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[4]);

                    }



                   // removes empty index

                   for(int i =0; i <vectorSocialNetworks2.size(); i++){

                            vectorSocialNetworks2.removeAll("");



                   }







                   if(vectorSocialNetworks2.size()  == *socialNetWorkNumPtr){

                          *socialNetWorkNumPtr=0; // done



                   }

                   if(vectorSocialNetworks2.contains(vectorSocialNetworks2.at(*socialNetWorkNumPtr))){

                          socialNetWork =  vectorSocialNetworks2.at(*socialNetWorkNumPtr);

                   }







                   (*keywordListSearchEngineCounterPtr)+=10;

                   /*****Cast num to string to put inside query string******/

                   castSearchQueryNumPtr = QString::number( *keywordListSearchEngineCounterPtr);






                   if(!ui->lineEdit_keywords_search_box->text().isEmpty())
                   {
                       currentKeywordSearchBoxKeyword = options[3]->keywordSearchBoxOptions[0];
                       ui->label_Current_Keyword->setText("Current Keyword: " + currentKeywordSearchBoxKeyword);

                       searchEngineParam = "https://www.bing.com/search?q=" +
                              socialNetWork +"%20"
                              +email+ "%20" + currentKeywordSearchBoxKeyword.replace(" ","+") +
                              "&qs=n&sp=-1&pq=undefined&sc=0-45&sk=&cvid=6C577B0F2A1348BBB5AF38F9AC4CA13A&first="
                               + castSearchQueryNumPtr +"&FORM=PERE";

                   }



                   if(!options[4]->keywordLoadListOptions.empty())
                   {
                       ui->label_Current_Keyword->setText("Current Keyword: " +  currentKeywordPtr->replace("+"," "));
                       searchEngineParam = "https://www.bing.com/search?q=" +
                              socialNetWork +"%20"
                              +email+ "%20" + currentKeywordPtr->replace(" ","+") +
                              "&qs=n&sp=-1&pq=undefined&sc=0-45&sk=&cvid=6C577B0F2A1348BBB5AF38F9AC4CA13A&first="
                               + castSearchQueryNumPtr +"&FORM=PERE";
                   }





                   // if both are not empty used currentKeywordPtr because the searchbox keyword is in the
                   // qlist/hash and will be eventuall processed
                   if(!options[4]->keywordLoadListOptions.empty() && !ui->lineEdit_keywords_search_box->text().isEmpty())
                   {
                       ui->label_Current_Keyword->setText("Current Keyword: " +  currentKeywordPtr->replace(" ","+"));


                   }



                       /****Continues email quene***/

                       if(*keywordListSearchEngineCounterPtr == 100){
                           if(*emailOptionsNumPtr <=   vectorEmailOptions.size()  ){
                                (*emailOptionsNumPtr)+=1;
                            }

                       }



                       /****Continues social network quene***/

                       if(*keywordListSearchEngineCounterPtr  == 100){
                           if(*socialNetWorkNumPtr <=   vectorSocialNetworks2.size()  ){
                               (*socialNetWorkNumPtr)+=1;

                             }
                       }





                       /*******Stops social network quene, and moves on to next******/

                       if(*keywordListSearchEngineCounterPtr  == 100){
                          *keywordListSearchEngineCounterPtr = 0;

                           // if social network pointer, and email options pointer is
                           //than the size of  socialNetworkOptions arrary,
                           //then were done, and move on

                           if(*socialNetWorkNumPtr ==  vectorSocialNetworks2.size()){

                               //(*socialNetWorkNumPtr)+=0;
                              //(*socialNetWorkNumPtr)+=1; //
                               //qDebug() << "MOVE ON";
                               // add one to it if theres a element before it
                               //vectorSocialNetwork   get current el, check to see if theres a el after it, then
                               // increment it
                              // (*searchEngineNumPtr)+=1;
                              // vectorSearchEngineOptions.at(*searchEngineNumPtr)

                               // if the last item in vector is true, and dosent match our current value

                               // theres more elements after our current element, we need

                               // this to make sure out pointer dosent get out of a range/QVector out of range.



                               if(!vectorSearchEngineOptions.last().isEmpty()){
                                   vectorSearchEngineOptionsLastItem = vectorSearchEngineOptions.last();
                                   if( vectorSearchEngineOptionsLastItem !=  vectorSearchEngineOptions.at(*searchEngineNumPtr) ){

                                               (*searchEngineNumPtr)+=1;

                                   }
                               }






                               /****Continues search engine quene***/

                              if(*keywordListSearchEngineCounterPtr == 100){
                                  // cant use above condition because were resetting
                                  //*keywordListSearchEngineCounterPtrto 0
                                    // (*searchEngineNumPtr )+=1; // this should only be used when were done scraping

                              }



                               /*****

                                 // MOVE ON TO NEXT

                                 //

                                 if next checkbox option is not checked skip it/add two two pointer

                                 by incrementing pointer by 2 we skip the checkbox option thats empty,

                                 and go to the next one, else dont skip it, and go to it --> increment by 1

                               *****/



                           }



                           if( *emailOptionsNumPtr > vectorEmailOptions.size()){
                               *emailOptionsNumPtr=0;
                           }
                       }


                     // qDebug() << searchEngineParam;
                     // qDebug()<<  searchEngine;
                     // qDebug()<<  vectorSearchEngineOptions;
                     // qDebug() << *keywordListSearchEngineCounterPtr;



               }



               /********Yahoo********/

               if(searchEngine == "http://yahoo.com" ){

                   /*******Email Options******/

                   vectorEmailOptions.clear();

                   for(int i =0; i < vectorEmailOptions.size(); i++){
                           vectorEmailOptions.removeAll(vectorEmailOptions.at(i));
                   }



                   if(ui->checkBox_Email_Gmail->isChecked()){
                       vectorEmailOptions.resize(1);
                       vectorEmailOptions.push_back(options[1]->emailOptions[0]);
                     }



                   if(ui->checkBox_Email_Yahoo->isChecked()){
                       vectorEmailOptions.resize(2);
                       vectorEmailOptions.push_back(options[1]->emailOptions[1]);
                    }



                   if(ui->checkBox_Email_Hotmail->isChecked()){
                        vectorEmailOptions.resize(3);
                        vectorEmailOptions.push_back(options[1]->emailOptions[2]);
                    }





                   // removes empty index

                   for(int i =0; i <vectorEmailOptions.size(); i++){
                            vectorEmailOptions.removeAll("");
                   }



                   if(vectorEmailOptions.size()  == *emailOptionsNumPtr){
                          *emailOptionsNumPtr=0; // done
                   }

                   if(vectorEmailOptions.contains(vectorEmailOptions.at(*emailOptionsNumPtr))){
                          email =  vectorEmailOptions.at(*emailOptionsNumPtr);
                   }



                   /*****Email Section done****/


                   // clears vector, if not we will keep resizing the vector on each timer

                   vectorSocialNetworks2.clear();
                   for(int i =0; i <vectorSocialNetworks2.size(); i++){
                            vectorSocialNetworks2.removeAll(vectorSocialNetworks2.at(i));

                   }





                   if(ui->checkBox_Social_Instagram->isChecked()){

                       vectorSocialNetworks2.resize(1);

                       vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[0]);





                     }



                   if(ui->checkBox_Social_Facebook->isChecked()){

                       vectorSocialNetworks2.resize(2);

                       vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[1]);

                    }



                   if(ui->checkBox_Social_Soundcloud->isChecked()){

                        vectorSocialNetworks2.resize(3);

                        vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[2]);

                    }



                   if(ui->checkBox_Social_Reverbnation->isChecked()){

                        vectorSocialNetworks2.resize(4);

                        vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[3]);

                    }



                   if(ui->checkBox_Social_Myspace->isChecked()){

                        vectorSocialNetworks2.resize(5);

                        vectorSocialNetworks2.push_back(options[2]->socialNetworkOptions[4]);

                    }



                   // removes empty index

                   for(int i =0; i <vectorSocialNetworks2.size(); i++){

                            vectorSocialNetworks2.removeAll("");



                   }







                   if(vectorSocialNetworks2.size()  == *socialNetWorkNumPtr){

                          *socialNetWorkNumPtr=0; // done



                   }

                   if(vectorSocialNetworks2.contains(vectorSocialNetworks2.at(*socialNetWorkNumPtr))){

                          socialNetWork =  vectorSocialNetworks2.at(*socialNetWorkNumPtr);

                   }







                   (*keywordListSearchEngineCounterPtr)+=10;

                   /*****Cast num to string to put inside query string******/

                   castSearchQueryNumPtr = QString::number( *keywordListSearchEngineCounterPtr);

                   if(!ui->lineEdit_keywords_search_box->text().isEmpty())
                   {


                       currentKeywordSearchBoxKeyword = options[3]->keywordSearchBoxOptions[0];
                       ui->label_Current_Keyword->setText("Current Keyword: " + currentKeywordSearchBoxKeyword);


                       searchEngineParam = "https://search.yahoo.com/search;_ylt=A2KIbNDlJS1b7nIAYNNx.9w4;_ylu=X3oDMTFjN3E2bWhuBGNvbG8DYmYxBHBvcwMxBHZ0aWQDVUkyRkJUMl8xBHNlYwNwYWdpbmF0aW9u?p=" +
                               socialNetWork +"%20"
                              +email+ "%20" + currentKeywordSearchBoxKeyword.replace(" ","+") +
                              "&ei=UTF-8&fr=yfp-hrmob&fr2=p%3Afp%2Cm%3Asb&_tsrc=yfp-hrmob&fp=1&b=11&pz=" + castSearchQueryNumPtr +"&xargs=0";

                   }



                   if(!options[4]->keywordLoadListOptions.empty())
                   {

                       ui->label_Current_Keyword->setText("Current Keyword: " +  currentKeywordPtr->replace("+"," "));

                       searchEngineParam = "https://search.yahoo.com/search;_ylt=A2KIbNDlJS1b7nIAYNNx.9w4;_ylu=X3oDMTFjN3E2bWhuBGNvbG8DYmYxBHBvcwMxBHZ0aWQDVUkyRkJUMl8xBHNlYwNwYWdpbmF0aW9u?p=" +
                               socialNetWork +"%20"
                              +email+ "%20" + currentKeywordPtr->replace(" ","+") +
                              "&ei=UTF-8&fr=yfp-hrmob&fr2=p%3Afp%2Cm%3Asb&_tsrc=yfp-hrmob&fp=1&b=11&pz=" + castSearchQueryNumPtr +"&xargs=0";

                   }

                   // if both are not empty used currentKeywordPtr because the searchbox keyword is in the
                   // qlist/hash and will be eventuall processed
                   if(!options[4]->keywordLoadListOptions.empty() && !ui->lineEdit_keywords_search_box->text().isEmpty())
                   {
                       ui->label_Current_Keyword->setText("Current Keyword: " +  currentKeywordPtr->replace("+"," "));


                   }






                       /****Continues email quene***/

                       if(*keywordListSearchEngineCounterPtr == 100){

                           if(*emailOptionsNumPtr <=   vectorEmailOptions.size()  ){

                                (*emailOptionsNumPtr)+=1;



                             }

                       }







                       /****Continues social network quene***/

                       if(*keywordListSearchEngineCounterPtr == 100){

                           if(*socialNetWorkNumPtr <=   vectorSocialNetworks2.size()  ){

                               (*socialNetWorkNumPtr)+=1;



                             }

                       }









                       /*******Stops social network quene, and moves on to next******/

                       if(*keywordListSearchEngineCounterPtr  == 100){

                         *keywordListSearchEngineCounterPtr = 0;



                           // if social network pointer, and email options pointer is

                           //than the size of  socialNetworkOptions arrary,

                           //then were done, and move on

                           if(*socialNetWorkNumPtr ==  vectorSocialNetworks2.size()){

                               //(*socialNetWorkNumPtr)+=0;

                              //(*socialNetWorkNumPtr)+=1; //

                               //qDebug() << "MOVE ON";

                               // add one to it if theres a element before it

                               //vectorSocialNetwork   get current el, check to see if theres a el after it, then

                               // increment it

                              // (*searchEngineNumPtr)+=1;

                              // vectorSearchEngineOptions.at(*searchEngineNumPtr)



                               // if the last item in vector is true, and dosent match our current value

                               // theres more elements after our current element, we need

                               // this to make sure out pointer dosent get out of a range/QVector out of range.



                               if(!vectorSearchEngineOptions.last().isEmpty()){

                                   vectorSearchEngineOptionsLastItem = vectorSearchEngineOptions.last();

                                   if( vectorSearchEngineOptionsLastItem !=  vectorSearchEngineOptions.at(*searchEngineNumPtr) ){

                                               (*searchEngineNumPtr)+=1;

                                   }

                               }



                               if(vectorSearchEngineOptions.size()  == *searchEngineNumPtr){

                                     // *searchEngineNumPtr+=1; // done



                               }

                               /****Continues search engine quene***/

                              // (*searchEngineNumPtr )+=1; // this should only be used when were done scraping





                               /****Continues search engine quene***/

                              if(*keywordListSearchEngineCounterPtr == 100){

                                  // cant use above condition because were resetting

                                  //*keywordListSearchEngineCounterPtr to 0

                                    // (*searchEngineNumPtr )+=1; // this should only be used when were done scraping

                              }



                               /*****

                                 // MOVE ON TO NEXT

                                 //

                                 if next checkbox option is not checked skip it/add two two pointer

                                 by incrementing pointer by 2 we skip the checkbox option thats empty,

                                 and go to the next one, else dont skip it, and go to it --> increment by 1

                               *****/



//                               if(!ui->checkBox_Bing->isChecked()){

//                                      (*searchEngineNumPtr)+=2;

//                               }

//                               if(ui->checkBox_Bing->isChecked()){

//                                      (*searchEngineNumPtr)+=1;

//                               }



                           }



                           if( *emailOptionsNumPtr > vectorEmailOptions.size()){

                               *emailOptionsNumPtr=0;

                           }

                       }

                     // qDebug() << searchEngineParam;
                     // qDebug()<<  searchEngine;
                     // qDebug()<<  vectorSearchEngineOptions;
                     // qDebug() << *keywordListSearchEngineCounterPtr;
            }

            /********End of All Scraping Code******/


           // if proxy server is empty emit a signal to let worker thread know
           // if there are no proxies, use users regular ip
           if(proxyServers->isEmpty())
           {
              emit emitsenderEmptyProxyServer("Empty");
              // qDebug() << "Main thread Empty??"<< *proxyServers;

           }

           if(!proxyServers->isEmpty())
           {
              emit emitsenderEmptyProxyServer("Not Empty");
             // qDebug() << "Main thread not empty??"<< *proxyServers;
           }

           // sending params/options signal after we done
           emit postParam(searchEngineParam,options[5]->userAgentsOptions[0],proxyServers);

           /****if timer is less or equal to search results combox box***/
           if(QString::number(*keywordListNumPtrCounter) == ui->comboBox_search_results_amount->currentText())
           {

              // worker->abort();
               //thread->quit();
              if(!options[4]->keywordLoadListOptions.isEmpty())
              {
                  filterCurrentKeyword = *currentKeywordPtr;
                  filterCurrentKeyword = filterCurrentKeyword.replace("+"," ");
                  QHash<QString,int>::const_iterator j = options[4]->keywordLoadListOptions.constBegin();
                  while(j != options[4]->keywordLoadListOptions.constEnd()){
                   // if keys inside hash does not match current keyword, and is not empty, there more elements
                      if(j.key() != filterCurrentKeyword)

                      {
                                 // if key is not empty, and value is 0/not tagged theres more elements ahead
                                 // mark it as one, and increment keywordlistptr
                                 if(!j.key().isEmpty() && j.value() == 0){

                                     // current keyword key can now be assigned 1 because were done with it
                                     options[4]->keywordLoadListOptions.insert(filterCurrentKeyword,1);
                                     // restart keywordList timer to start again with new keyword in hash
                                     *keywordListNumPtrCounter = 0;


                                 }

                                 // if key is not empty, and value is 1/tagged,
                                 // we still want to increase keywordlistptr to get the next keyword in list

                                  if(!j.key().isEmpty() && j.value() == 1){
                                     // if the hash key is empty theres no more keywords, so stop scraping
                                     // and stop all threads.
                                     //thread->quit();
                                     //worker->abort();
                                     *keywordListNumPtrCounter = 0;
                                     //ui->pushButton_Start->setText("Start");
                                     //qDebug() << options[4]->keywordLoadListOptions;

                                 }

                                  // we have to figure out when were done using all the keywords in list??
                                  if(j.value() == 1 && j.value() != 0){
                                      //*keywordListNumPtrCounter = 0;
                                     // thread->quit();
                                     // worker->abort();
                                     // ui->pushButton_Start->setText("Start");
                                  }
                      }
                      else
                      {
                        //qDebug() << j.value();
                      }
                       j++;
                  }// end while looo

                // qDebug() <<options[4]->keywordLoadListOptions;
                // qDebug() << "keywordlistptr--->>" << *keywordListNumPtrCounter;

              }
              else
              {

              }

           }

           else
           {
               qDebug() <<QString::number(*keywordListNumPtrCounter);
              // qDebug() << ui->comboBox_search_results_amount->currentText();

           }//  end of checking end of results

}



void MainWindow::receiverEmailList(QString list)


{
         QString emailsToLowerCase;
         // assign qlist from thread to emailList pointer
         *emailList << list;
        // convert qlis to qset to remove dups
         QSet<QString> set = emailList->toSet();
        // convert qset back to list
         setEmailList = set.toList();
         for(int i = 0; i < setEmailList.size(); i++)
         {


            // qDebug() << setEmailList.at(i);
             emailsToLowerCase = setEmailList.at(i);
             ui->tableWidget_Emails->setItem(i, 0, new QTableWidgetItem(setEmailList.at(i).toLower()));
             ui->tableWidget_Emails->showRow(i);

             // only show up to 20 at any given time
//             if(i <=  *nextEmailPaginationPtr || i >= *previousEmailPaginationPtr){
//                 qDebug() <<"increment -->" << i ;
//                 qDebug() <<"next--> "<<  *nextEmailPaginationPtr;
//                 qDebug() <<"previous-->" <<*previousEmailPaginationPtr;
//                ui->tableWidget_Emails->setItem(i, 0, new QTableWidgetItem(setEmailList.at(i)));

//             }


             if(i <=  *nextEmailPaginationPtr || i >= *previousEmailPaginationPtr )
             {
                // qDebug() <<"emails -->" << setEmailList.at(i) ;
                 //ui->tableWidget_Emails->setRowCount(*nextEmailPaginationPtr);
                // ui->tableWidget_Emails->setItem(i, 0, new QTableWidgetItem(setEmailList.at(i)));


             }

         }// end of outer for loop

        for(int j =0;  j < ui->tableWidget_Emails->rowCount();  j ++)
        {
              //qDebug() << j;
//            if(ui->tableWidget_Emails->item(j,0)->text().isEmpty())
//            {
//                ui->tableWidget_Emails->hideRow(j);
//            }else{

//                ui->tableWidget_Emails->showRow(j);
//            }

        }





         // items found on bottom status bar
         ui->label_Items_Found->setText("Items Found: " +QString::number(setEmailList.size()));

        // ui->pushButton_Next_Email_Pagination->show();
         //ui->pushButton_Previous_Email_Pagination->show();



//            for(int j  = *previousEmailPaginationPtr; j <= *nextEmailPaginationPtr; j++){
//                //ui->tableWidget_Emails->setItem(i, 0, new QTableWidgetItem(QString("@gmail.com")));

//                if(j <= setEmailList.size())
//                {

//                }
//                //qDebug() << j;
//            }


}


void MainWindow::recieverProxyTableSelection(const QItemSelection &selected, const QItemSelection &deselected)

{


          /**********
             selected which is a type of QItemSelection object
             is a type, which is QModelIndexList, this type gives us a method-
             called indexes(), which return a type of  QModelIndexList object.
             This object holds nested objects, objects within objects.
             These inner objects are type QModelIndex
             So we have to iterate/loop through the QModelIndex;

             We can do that by a foreach loop.
             We create a type of QModelIndex that will be a object.
             Through each iteration/loop we assign the inner objects to &index
             which is a reference. We then can now access the QModexlIndexes,
             which were once nested.

          *******/

          QModelIndexList  indexes = selected.indexes();
          if(ui->checkBox_Delete_Proxy->isChecked()){
              foreach(const QModelIndex &index,indexes){

                  // removes row user has selected
                  ui->tableWidget_Proxy->removeRow(index.row());
                  // removes proxy servers from qstring list, if user has added proxies
                  proxyServers->removeAt(index.row());

              }
          }

}



void MainWindow::recieverKeywordsQueue(){
    QStringList keywordQueueTableHeaders;
    QStringList keywordKey;
    QList <int> keywordValue;
    QHash<QString,int>::const_iterator i = options[4]->keywordLoadListOptions.constBegin();
    QString filterCurrentKeyword;
    filterCurrentKeyword = currentKeywordPtr->replace("+"," ");
    while(i != options[4]->keywordLoadListOptions.constEnd()){
             if(!i.key().isEmpty())
             {
                 keywordKey << i.key();
             }

             keywordValue << i.value();
            i++;
    }


    keywordQueueTableHeaders  << "Keywords" << "Status";
    ui->tableWidget_Keywords_Queue->setRowCount(keywordKey.size());
    ui->tableWidget_Keywords_Queue->setColumnCount(2);

    for(int row = 0; row <  keywordKey.size(); row++)
    {
            for(int col =0; col < 2; col++)
            {

                // if current keyword matches this item, change set item string to "Currently Processing"
                // if keyword is 1/done change it to "Complete"
                // if keyword is 0 /not dont change it to "Waiting.."

                if(col == 0)
                {
                        ui->tableWidget_Keywords_Queue->setItem(row, col, new QTableWidgetItem(keywordKey.at(row)));
                }



                if(col == 1)
                {
                       // qDebug() << *currentKeywordPtr;
                       // if current keyword matches a keyword in our row change it to "Processing"
                       // else change it to "Waiting"
                        QString test = keywordKey.at(row);
                        if(filterCurrentKeyword == keywordKey.at(row) && keywordValue.at(row) ==0  && !test.isEmpty())
                        {

                            if(clickedStartStopButton == false){
                                ui->tableWidget_Keywords_Queue->setItem(row, col, new QTableWidgetItem("Aborted"));

                            }
                            if(clickedStartStopButton == true){
                                ui->tableWidget_Keywords_Queue->setItem(row, col, new QTableWidgetItem("Processing..."));

                            }
                           //ui->tableWidget_Keywords_Queue->setItem(row, col, new QTableWidgetItem("Processing..."));
                          // ui->tableWidget_Keywords_Queue->item(row,col)->setBackground(QBrush(QColor(250,0,0)));
                        }

                       // keyword does not match current keyword
                       if(filterCurrentKeyword != keywordKey.at(row) && keywordValue.at(row) ==0   && !test.isEmpty())
                       {
                           ui->tableWidget_Keywords_Queue->setItem(row, col, new QTableWidgetItem("Waiting..."));
                       }

                       // if keyword is done
                       if(keywordValue.at(row) == 1 && filterCurrentKeyword != keywordKey.at(row)  && !test.isEmpty())
                       {
                           ui->tableWidget_Keywords_Queue->setItem(row, col, new QTableWidgetItem("Completed..."));
                       }

                }


            }// end of for inner loop

      } // end of for outer loop

    ui->tableWidget_Keywords_Queue->setHorizontalHeaderLabels(keywordQueueTableHeaders);
    ui->tableWidget_Keywords_Queue->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_Keywords_Queue->resizeRowsToContents();






}

void MainWindow::deleteKeyordsListTable(){
    // create empty table
    ui->tableWidget_Keywords_Queue->setRowCount(0);
    ui->tableWidget_Keywords_Queue->setColumnCount(0);
    *currentKeywordPtr = "";

}

void MainWindow::deleteEmailsListTable(){
    // create empty table
    ui->tableWidget_Emails->resizeRowsToContents();

    for(int i = 0; i < setEmailList.size(); i++)
    {
        ui->tableWidget_Emails->setItem(i, 0, new QTableWidgetItem(""));
        ui->tableWidget_Emails->hideRow(i);

    }
    // clear email qtlist
    emailList->clear();
    // clear email qt set
    setEmailList.clear();


}


void MainWindow::recieverCurlResponseInfo(QString info)
{
    //qDebug() << info;

    if(info == "Proxy Error" || info ==  "503")
    {

        ui->label_Curl_Status->setText("Status: Proxy failed, or Server is Temporarily Unavailable");
        //QTimer::singleShot(10,this,SLOT(deleteEmailsListTable()));
        //emailList->clear();
        ui->label_Items_Found->setText("Items Found: ");
        qDebug() << "Proxy or 503 Error";

    }
    else if(info == "Request Succeded")
    {
        ui->label_Curl_Status->setText("Status: Successfully Crawling");

    }
}



void MainWindow::on_pushButton_Add_Proxy_clicked()
{
    QStringList proxyTableHeaders;
    if(!ui->lineEdit_Proxy_Port->text().isEmpty() && !ui->lineEdit_Proxy_Host->text().isEmpty() )

    {



    }
    // Anytime add proxy button is clicked we increment a counter to become the index for the current proxy
    (*addProxyCounterPtr)+=1;
    //insert proxy into qlist
    proxyServers->insert(*addProxyCounterPtr,ui->lineEdit_Proxy_Host->text()+":"  + ui->lineEdit_Proxy_Port->text());
    proxyTableHeaders  << "Proxy Server" << "Proxy Port";
    ui->tableWidget_Proxy->setRowCount(proxyServers->size());
    ui->tableWidget_Proxy->setColumnCount(2);
    // loops through the size of the proxyServer qlist
    for(int row = 0; row < proxyServers->size(); row++)
    {

            QString url = "http://"+proxyServers->at(row);
            QUrl server(url);

            // validates proxy host
            QRegExp host("[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}");
            QRegExpValidator hostValidator(host, 0);
            QString proxyHostString;
            int proxyHostPosition = 0;
            proxyHostString= ui->lineEdit_Proxy_Host->text();

            // validates proxy port
            QRegExp port("((?:))(?:[0-9]+)$");
            QRegExpValidator portValidator(port, 0);
            QString  proxyPortString;
            int proxyPortPosition = 0;
            proxyPortString = ui->lineEdit_Proxy_Port->text();

            // if proxy host regex does not validate to 2,its invalid
            if(hostValidator.validate(proxyHostString, proxyHostPosition) !=2)
            {

                // remove current proxy from proxyServer qlist
                proxyServers->removeAll(ui->lineEdit_Proxy_Host->text()+":"  + ui->lineEdit_Proxy_Port->text());
                QMessageBox::warning(this,"...","Proxy server error, please enter a valid proxy server");
                isProxyHostValid = false;
                break;

            }

            else

            {
                isProxyHostValid = true;
            }


            // if proxy port regex does not validate to 2,its invalid
            if(portValidator.validate(proxyPortString, proxyPortPosition) !=2)
            {
                // remove current proxy from proxyServer qlist
                proxyServers->removeAll(ui->lineEdit_Proxy_Host->text()+":"  + ui->lineEdit_Proxy_Port->text());
                QMessageBox::warning(this,"...","Proxy port error, please enter a valid port");
                isProxyPortValid = false;
                break;
            }

            else

            {
                isProxyPortValid = true;
            }


          // qDebug() <<*proxyServers;


            for(int col =0; col < 2; col++)
            {


                 // if both proxy port, and proxy sever is valid, add it to table
                if((portValidator.validate(proxyPortString, proxyPortPosition) ==2) && (hostValidator.validate(proxyHostString, proxyHostPosition) ==2))
                {
                    if(col == 1)
                    {
                        ui->tableWidget_Proxy->setItem(row, col, new QTableWidgetItem(QString::number(server.port())));
                       // qDebug() << *addProxyCounterPtr;
                    }

                }


                if((portValidator.validate(proxyPortString, proxyPortPosition) ==2) && (hostValidator.validate(proxyHostString, proxyHostPosition) ==2))
                {

                    if(col == 0)
                    {

                        ui->tableWidget_Proxy->setItem(row, col, new QTableWidgetItem(server.host()));

                    }
                }

            }// end of inner loop

      }// outer for loop

    ui->tableWidget_Proxy->setHorizontalHeaderLabels(proxyTableHeaders);
    ui->tableWidget_Proxy->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_Proxy->resizeRowsToContents();

}



void MainWindow::on_checkBox_Delete_Keywords_clicked()
{

    if(ui->checkBox_Delete_Keywords->isChecked())
    {
        QTimer::singleShot(100,this,SLOT(deleteKeyordsListTable()));
        options[4]->keywordLoadListOptions.clear();
        ui->lineEdit_Keyword_List_File_Location->setText("");

    }
}



void MainWindow::on_checkBox_Delete_Emails_clicked()
{
    if(ui->checkBox_Delete_Emails->isChecked())
    {
        QTimer::singleShot(100,this,SLOT(deleteEmailsListTable()));
       // emailList->clear();
       // setEmailList.clear();
        ui->label_Items_Found->setText("Items Found: ");


    }

}



void MainWindow::on_pushButton_Next_Email_Pagination_clicked()
{
    (*nextEmailPaginationPtr)+=20;

    if(*nextEmailPaginationPtr >=40){

        (*previousEmailPaginationPtr)+=20;

    }


}

void MainWindow::on_pushButton_Previous_Email_Pagination_clicked()
{
    if(*previousEmailPaginationPtr >= 20){
         (*previousEmailPaginationPtr)-=20;
         (*nextEmailPaginationPtr)-=20;
    }



}


