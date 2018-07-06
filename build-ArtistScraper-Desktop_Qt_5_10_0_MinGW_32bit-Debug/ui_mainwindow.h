/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit_keywords_search_box;
    QComboBox *comboBox_search_results_amount;
    QLabel *label_search_results_amount;
    QLabel *label_search_engine;
    QLabel *label_search_engine_keywords;
    QFrame *line;
    QPushButton *pushButton_Start;
    QTabWidget *tabWidget_Queue_Keywords;
    QWidget *tab_3;
    QTableWidget *tableWidget_Emails;
    QPushButton *pushButton_Save;
    QWidget *tab;
    QTableWidget *tableWidget_Keywords_Queue;
    QWidget *tab_4;
    QTabWidget *tabWidget_Options;
    QWidget *tab_6;
    QLabel *label_Search_Engine_Label_Option;
    QListView *listView_Search_Engine_Option;
    QCheckBox *checkBox_Google;
    QCheckBox *checkBox_Bing;
    QCheckBox *checkBox_Yahoo;
    QListView *listView;
    QLabel *label_UserAgent;
    QRadioButton *radioButton_Android_Webkit;
    QRadioButton *radioButton_Blackberry;
    QRadioButton *radioButton_IE_Mobile;
    QWidget *tab_7;
    QLabel *label_Email_Provider_Option_Label;
    QListView *listView_Email_Provider_Option_Label;
    QCheckBox *checkBox_Email_Gmail;
    QCheckBox *checkBox_Email_Yahoo;
    QCheckBox *checkBox_Email_Hotmail;
    QWidget *tab_8;
    QListView *listView_Social_Networks_Option;
    QLabel *label_Social_Networks_Option_Label;
    QCheckBox *checkBox_Social_Instagram;
    QCheckBox *checkBox_Social_Facebook;
    QCheckBox *checkBox_Social_Soundcloud;
    QCheckBox *checkBox_Social_Reverbnation;
    QCheckBox *checkBox_Social_Myspace;
    QWidget *tab_5;
    QTableView *tableView_Proxy;
    QTableWidget *tableWidget_Proxy;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_Proxy_Host;
    QLineEdit *lineEdit_Proxy_Port;
    QPushButton *pushButton_Add_Proxy;
    QCheckBox *checkBox_Delete_Proxy;
    QPushButton *pushButton_Load_Proxies;
    QFrame *line_2;
    QPushButton *pushButton_Load_Keyword_List;
    QLabel *label_Current_Keyword;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(638, 448);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit_keywords_search_box = new QLineEdit(centralWidget);
        lineEdit_keywords_search_box->setObjectName(QStringLiteral("lineEdit_keywords_search_box"));
        lineEdit_keywords_search_box->setGeometry(QRect(190, 10, 291, 21));
        comboBox_search_results_amount = new QComboBox(centralWidget);
        comboBox_search_results_amount->setObjectName(QStringLiteral("comboBox_search_results_amount"));
        comboBox_search_results_amount->setGeometry(QRect(190, 40, 72, 22));
        label_search_results_amount = new QLabel(centralWidget);
        label_search_results_amount->setObjectName(QStringLiteral("label_search_results_amount"));
        label_search_results_amount->setGeometry(QRect(20, 40, 171, 16));
        label_search_engine = new QLabel(centralWidget);
        label_search_engine->setObjectName(QStringLiteral("label_search_engine"));
        label_search_engine->setGeometry(QRect(20, 10, 101, 16));
        label_search_engine_keywords = new QLabel(centralWidget);
        label_search_engine_keywords->setObjectName(QStringLiteral("label_search_engine_keywords"));
        label_search_engine_keywords->setGeometry(QRect(130, 10, 61, 16));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(-10, 60, 651, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_Start = new QPushButton(centralWidget);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));
        pushButton_Start->setGeometry(QRect(10, 80, 80, 21));
        tabWidget_Queue_Keywords = new QTabWidget(centralWidget);
        tabWidget_Queue_Keywords->setObjectName(QStringLiteral("tabWidget_Queue_Keywords"));
        tabWidget_Queue_Keywords->setGeometry(QRect(10, 120, 621, 281));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tableWidget_Emails = new QTableWidget(tab_3);
        tableWidget_Emails->setObjectName(QStringLiteral("tableWidget_Emails"));
        tableWidget_Emails->setGeometry(QRect(10, 10, 591, 201));
        pushButton_Save = new QPushButton(tab_3);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));
        pushButton_Save->setGeometry(QRect(450, 220, 61, 21));
        tabWidget_Queue_Keywords->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tableWidget_Keywords_Queue = new QTableWidget(tab);
        tableWidget_Keywords_Queue->setObjectName(QStringLiteral("tableWidget_Keywords_Queue"));
        tableWidget_Keywords_Queue->setGeometry(QRect(10, 10, 591, 231));
        tabWidget_Queue_Keywords->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget_Options = new QTabWidget(tab_4);
        tabWidget_Options->setObjectName(QStringLiteral("tabWidget_Options"));
        tabWidget_Options->setGeometry(QRect(10, 10, 601, 231));
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        label_Search_Engine_Label_Option = new QLabel(tab_6);
        label_Search_Engine_Label_Option->setObjectName(QStringLiteral("label_Search_Engine_Label_Option"));
        label_Search_Engine_Label_Option->setGeometry(QRect(10, 10, 181, 16));
        listView_Search_Engine_Option = new QListView(tab_6);
        listView_Search_Engine_Option->setObjectName(QStringLiteral("listView_Search_Engine_Option"));
        listView_Search_Engine_Option->setGeometry(QRect(10, 30, 221, 141));
        checkBox_Google = new QCheckBox(tab_6);
        checkBox_Google->setObjectName(QStringLiteral("checkBox_Google"));
        checkBox_Google->setGeometry(QRect(20, 40, 72, 19));
        checkBox_Bing = new QCheckBox(tab_6);
        checkBox_Bing->setObjectName(QStringLiteral("checkBox_Bing"));
        checkBox_Bing->setGeometry(QRect(20, 60, 72, 19));
        checkBox_Yahoo = new QCheckBox(tab_6);
        checkBox_Yahoo->setObjectName(QStringLiteral("checkBox_Yahoo"));
        checkBox_Yahoo->setGeometry(QRect(20, 80, 72, 19));
        listView = new QListView(tab_6);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(280, 30, 221, 141));
        label_UserAgent = new QLabel(tab_6);
        label_UserAgent->setObjectName(QStringLiteral("label_UserAgent"));
        label_UserAgent->setGeometry(QRect(280, 10, 181, 16));
        radioButton_Android_Webkit = new QRadioButton(tab_6);
        radioButton_Android_Webkit->setObjectName(QStringLiteral("radioButton_Android_Webkit"));
        radioButton_Android_Webkit->setGeometry(QRect(290, 40, 111, 19));
        radioButton_Blackberry = new QRadioButton(tab_6);
        radioButton_Blackberry->setObjectName(QStringLiteral("radioButton_Blackberry"));
        radioButton_Blackberry->setGeometry(QRect(290, 60, 84, 19));
        radioButton_IE_Mobile = new QRadioButton(tab_6);
        radioButton_IE_Mobile->setObjectName(QStringLiteral("radioButton_IE_Mobile"));
        radioButton_IE_Mobile->setGeometry(QRect(290, 80, 84, 19));
        tabWidget_Options->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        label_Email_Provider_Option_Label = new QLabel(tab_7);
        label_Email_Provider_Option_Label->setObjectName(QStringLiteral("label_Email_Provider_Option_Label"));
        label_Email_Provider_Option_Label->setGeometry(QRect(10, 10, 181, 16));
        listView_Email_Provider_Option_Label = new QListView(tab_7);
        listView_Email_Provider_Option_Label->setObjectName(QStringLiteral("listView_Email_Provider_Option_Label"));
        listView_Email_Provider_Option_Label->setGeometry(QRect(10, 30, 221, 141));
        checkBox_Email_Gmail = new QCheckBox(tab_7);
        checkBox_Email_Gmail->setObjectName(QStringLiteral("checkBox_Email_Gmail"));
        checkBox_Email_Gmail->setGeometry(QRect(20, 40, 72, 19));
        checkBox_Email_Yahoo = new QCheckBox(tab_7);
        checkBox_Email_Yahoo->setObjectName(QStringLiteral("checkBox_Email_Yahoo"));
        checkBox_Email_Yahoo->setGeometry(QRect(20, 60, 72, 19));
        checkBox_Email_Hotmail = new QCheckBox(tab_7);
        checkBox_Email_Hotmail->setObjectName(QStringLiteral("checkBox_Email_Hotmail"));
        checkBox_Email_Hotmail->setGeometry(QRect(20, 80, 72, 19));
        tabWidget_Options->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        listView_Social_Networks_Option = new QListView(tab_8);
        listView_Social_Networks_Option->setObjectName(QStringLiteral("listView_Social_Networks_Option"));
        listView_Social_Networks_Option->setGeometry(QRect(10, 30, 221, 141));
        label_Social_Networks_Option_Label = new QLabel(tab_8);
        label_Social_Networks_Option_Label->setObjectName(QStringLiteral("label_Social_Networks_Option_Label"));
        label_Social_Networks_Option_Label->setGeometry(QRect(10, 10, 181, 16));
        checkBox_Social_Instagram = new QCheckBox(tab_8);
        checkBox_Social_Instagram->setObjectName(QStringLiteral("checkBox_Social_Instagram"));
        checkBox_Social_Instagram->setGeometry(QRect(20, 40, 72, 19));
        checkBox_Social_Facebook = new QCheckBox(tab_8);
        checkBox_Social_Facebook->setObjectName(QStringLiteral("checkBox_Social_Facebook"));
        checkBox_Social_Facebook->setGeometry(QRect(20, 60, 72, 19));
        checkBox_Social_Soundcloud = new QCheckBox(tab_8);
        checkBox_Social_Soundcloud->setObjectName(QStringLiteral("checkBox_Social_Soundcloud"));
        checkBox_Social_Soundcloud->setGeometry(QRect(20, 80, 81, 19));
        checkBox_Social_Reverbnation = new QCheckBox(tab_8);
        checkBox_Social_Reverbnation->setObjectName(QStringLiteral("checkBox_Social_Reverbnation"));
        checkBox_Social_Reverbnation->setGeometry(QRect(20, 100, 91, 19));
        checkBox_Social_Myspace = new QCheckBox(tab_8);
        checkBox_Social_Myspace->setObjectName(QStringLiteral("checkBox_Social_Myspace"));
        checkBox_Social_Myspace->setGeometry(QRect(20, 120, 72, 19));
        tabWidget_Options->addTab(tab_8, QString());
        tabWidget_Queue_Keywords->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tableView_Proxy = new QTableView(tab_5);
        tableView_Proxy->setObjectName(QStringLiteral("tableView_Proxy"));
        tableView_Proxy->setGeometry(QRect(10, 10, 601, 231));
        tableWidget_Proxy = new QTableWidget(tab_5);
        tableWidget_Proxy->setObjectName(QStringLiteral("tableWidget_Proxy"));
        tableWidget_Proxy->setGeometry(QRect(20, 20, 231, 181));
        label = new QLabel(tab_5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 20, 81, 16));
        label_2 = new QLabel(tab_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(350, 50, 61, 16));
        lineEdit_Proxy_Host = new QLineEdit(tab_5);
        lineEdit_Proxy_Host->setObjectName(QStringLiteral("lineEdit_Proxy_Host"));
        lineEdit_Proxy_Host->setGeometry(QRect(430, 20, 113, 21));
        lineEdit_Proxy_Port = new QLineEdit(tab_5);
        lineEdit_Proxy_Port->setObjectName(QStringLiteral("lineEdit_Proxy_Port"));
        lineEdit_Proxy_Port->setGeometry(QRect(430, 50, 61, 21));
        pushButton_Add_Proxy = new QPushButton(tab_5);
        pushButton_Add_Proxy->setObjectName(QStringLiteral("pushButton_Add_Proxy"));
        pushButton_Add_Proxy->setGeometry(QRect(430, 80, 80, 21));
        checkBox_Delete_Proxy = new QCheckBox(tab_5);
        checkBox_Delete_Proxy->setObjectName(QStringLiteral("checkBox_Delete_Proxy"));
        checkBox_Delete_Proxy->setGeometry(QRect(160, 210, 91, 19));
        pushButton_Load_Proxies = new QPushButton(tab_5);
        pushButton_Load_Proxies->setObjectName(QStringLiteral("pushButton_Load_Proxies"));
        pushButton_Load_Proxies->setGeometry(QRect(270, 180, 80, 21));
        tabWidget_Queue_Keywords->addTab(tab_5, QString());
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 100, 661, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        pushButton_Load_Keyword_List = new QPushButton(centralWidget);
        pushButton_Load_Keyword_List->setObjectName(QStringLiteral("pushButton_Load_Keyword_List"));
        pushButton_Load_Keyword_List->setGeometry(QRect(490, 10, 71, 21));
        label_Current_Keyword = new QLabel(centralWidget);
        label_Current_Keyword->setObjectName(QStringLiteral("label_Current_Keyword"));
        label_Current_Keyword->setGeometry(QRect(416, 80, 201, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 638, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget_Queue_Keywords->setCurrentIndex(3);
        tabWidget_Options->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_search_results_amount->setText(QApplication::translate("MainWindow", "Number of search results to parse", nullptr));
        label_search_engine->setText(QApplication::translate("MainWindow", "Use Search Engine", nullptr));
        label_search_engine_keywords->setText(QApplication::translate("MainWindow", "Keyword", nullptr));
        pushButton_Start->setText(QApplication::translate("MainWindow", "Start", nullptr));
        pushButton_Save->setText(QApplication::translate("MainWindow", "Save", nullptr));
        tabWidget_Queue_Keywords->setTabText(tabWidget_Queue_Keywords->indexOf(tab_3), QApplication::translate("MainWindow", "Harvested Emails", nullptr));
        tabWidget_Queue_Keywords->setTabText(tabWidget_Queue_Keywords->indexOf(tab), QApplication::translate("MainWindow", "Queue Keywords", nullptr));
        label_Search_Engine_Label_Option->setText(QApplication::translate("MainWindow", "Parse selected Search Engines Only", nullptr));
        checkBox_Google->setText(QApplication::translate("MainWindow", "google", nullptr));
        checkBox_Bing->setText(QApplication::translate("MainWindow", "bing", nullptr));
        checkBox_Yahoo->setText(QApplication::translate("MainWindow", "yahoo", nullptr));
        label_UserAgent->setText(QApplication::translate("MainWindow", "User Agents", nullptr));
        radioButton_Android_Webkit->setText(QApplication::translate("MainWindow", "Android Web Kit", nullptr));
        radioButton_Blackberry->setText(QApplication::translate("MainWindow", "Blackberry", nullptr));
        radioButton_IE_Mobile->setText(QApplication::translate("MainWindow", "IE Mobile", nullptr));
        tabWidget_Options->setTabText(tabWidget_Options->indexOf(tab_6), QApplication::translate("MainWindow", "Search Engine", nullptr));
        label_Email_Provider_Option_Label->setText(QApplication::translate("MainWindow", "Parse selected Emails Only", nullptr));
        checkBox_Email_Gmail->setText(QApplication::translate("MainWindow", "gmail", nullptr));
        checkBox_Email_Yahoo->setText(QApplication::translate("MainWindow", "yahoo", nullptr));
        checkBox_Email_Hotmail->setText(QApplication::translate("MainWindow", "hotmail", nullptr));
        tabWidget_Options->setTabText(tabWidget_Options->indexOf(tab_7), QApplication::translate("MainWindow", "Emails", nullptr));
        label_Social_Networks_Option_Label->setText(QApplication::translate("MainWindow", "Parse selected Social Networks  Only", nullptr));
        checkBox_Social_Instagram->setText(QApplication::translate("MainWindow", "instagram", nullptr));
        checkBox_Social_Facebook->setText(QApplication::translate("MainWindow", "facebook", nullptr));
        checkBox_Social_Soundcloud->setText(QApplication::translate("MainWindow", "soundcloud", nullptr));
        checkBox_Social_Reverbnation->setText(QApplication::translate("MainWindow", "reverbnation", nullptr));
        checkBox_Social_Myspace->setText(QApplication::translate("MainWindow", "myspace", nullptr));
        tabWidget_Options->setTabText(tabWidget_Options->indexOf(tab_8), QApplication::translate("MainWindow", "Social Networks", nullptr));
        tabWidget_Queue_Keywords->setTabText(tabWidget_Queue_Keywords->indexOf(tab_4), QApplication::translate("MainWindow", "Options", nullptr));
        label->setText(QApplication::translate("MainWindow", "Proxy Server", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Proxy Port", nullptr));
        pushButton_Add_Proxy->setText(QApplication::translate("MainWindow", "Add Proxy", nullptr));
        checkBox_Delete_Proxy->setText(QApplication::translate("MainWindow", "Delete Proxy", nullptr));
        pushButton_Load_Proxies->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        tabWidget_Queue_Keywords->setTabText(tabWidget_Queue_Keywords->indexOf(tab_5), QApplication::translate("MainWindow", "Proxies", nullptr));
        pushButton_Load_Keyword_List->setText(QApplication::translate("MainWindow", "Load List", nullptr));
        label_Current_Keyword->setText(QApplication::translate("MainWindow", "Current Keyword:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
