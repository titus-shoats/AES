#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "options.h"
#include <QStandardItemModel>
#include "curl/curl.h"
#include <QEvent>
#include <cstdio>
#include <string>
#include <QTimer>
#include <QVector>
#include <QString>
#include "worker.h"
#include  <QUrl>
#include <QThread>
#include <QItemSelection>
#include <QAbstractItemView>



namespace Ui {
class MainWindow;
}

typedef Options* OptionsPtr;
typedef QStringList *ProxyList;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setProxyTable();
    void setSearchResults();
    void getKeywordsSearchBoxOrList();
    void keywordSearchBoxProcess();
    void keywordListOptionProcess();
    void setEmailTable();


private slots:


    void on_pushButton_Start_clicked(bool checked);
    void on_pushButton_Load_Keyword_List_clicked();
    bool eventFilter(QObject *watched,QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void on_pushButton_Add_Proxy_clicked();
    void on_checkBox_Delete_Keywords_clicked();

    void on_pushButton_Next_Email_Pagination_clicked();

    void on_pushButton_Previous_Email_Pagination_clicked();

    void on_checkBox_Delete_Emails_clicked();

public slots:

      void receiverEmailList(QString);
      void receiverParameters();
      void recieverProxyTableSelection(const QItemSelection &,const QItemSelection &);
      void recieverKeywordsQueue();
      void recieverCurlResponseInfo(QString info);
      void deleteKeyordsListTable();
      void deleteEmailsListTable();

signals:
    void postParam(QString,QString,QList <QString> *);
    void emitParameters();
    void emitsenderEmptyProxyServer(QString);
    void emitsenderStopThreadCounters(QString);
    void emitsenderStartThreadCounters(QString);


private:
    Ui::MainWindow *ui;
    bool *startScrape;
    bool stopScrape;
    bool changeBool;
    const int numOptions = 67;
    // Options pointer
    OptionsPtr *options;
    // Options objects
    Options *opt;
    QStringList *proxyList;
    QStandardItemModel* proxyModelTable;
    QStandardItemModel* emailModelTable;

    static QStringList * emails;
    QTimer * timer;
    int *emailOptionsNumPtr;
    int *searchEngineNumPtr;
    int *searchEngineNumPtr1[3];
    int *socialNetWorkNumPtr;
    int *keywordLoadListOptionsNumPtr;

    int *addProxyCounterPtr;
    int addProxyCounterNum;

    int *keywordBoxNumPtrCounter;
    int keywordBoxNumPtrNum;

    int *keywordListSearchEngineCounterPtr;
    int keywordListSearchEngineCounterNum;

    int *keywordSearchBoxSearchEngineCounterPtr;
    int keywordSearchBoxSearchEngineCounterNum;

    int keywordListNumPtrNum;
    int * keywordListNumPtrCounter;

    bool isSearchEngineSelectOne;
    bool  isSocialNetworkSelectOne;
    bool isEmailSelectOne;
    bool isKeywordsSelect;

    bool  isProxyPortValid;
    bool  isProxyHostValid;

    QList <QString> *emailList;
    // sets QSet back to list
    // this is because were setting a qlist to qset to remove dups, then from a qset to qlist again
    QList <QString> setEmailList;
    QList <QString> *proxyServers;

    QThread *thread;
    Worker * worker;

    int emailOptionsNum;
    int searchEngineNum;
    int socialNetWorkNum;
    int keywordLoadListOptionsNum;
    bool * searchEngineNumPtrAdded;
    bool searchEngineNumPtrAddedBool;
    int *searchEngineNumPtrCounter;
    int  searchEngineNumPtrNum;
    QVector<QString>vectorSocialNetworks2;
    QVector<QString>vectorEmailOptions;
    QVector<QString>vectorSearchEngineOptions;
    QString *currentKeywordPtr;
    QString currentKeyword;
    QVector<QString>vector;
    QString *data;

    QUrl url;
    QString testLabel;
    // gets callback data from curl
    static QString * fetchWriteCallBackCurlData;
    QString fetchWriteCallBackCurlDataString;
    int * nextEmailPaginationPtr;
    int * previousEmailPaginationPtr;
    int nextEmailPagination;
    int previousEmailPagination;
    bool clickedStartStopButton;


};

#endif // MAINWINDOW_H
