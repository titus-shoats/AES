#ifndef OPTIONS_H
#define OPTIONS_H

#include <QString>
#include <QVector>


class Options{

public:
    // valid options "google","bing","yahoo"
    QString searchEngineOptions[3];
    //{"gmail","hotmail","outlook"};
    QString emailOptions[3];
    //valid options {"instagram","facebook","soundcloud"};
    QString socialNetworkOptions[5];
    //valid options , keywords that user inserts;
    QString keywordSearchBoxOptions[1];
    //valid options , userAgent will hold the current user agent string
    QString userAgentsOptions[1];
    //valid options , load list of keywords into array;
    QHash<QString,int> keywordLoadListOptions;




};

#endif // OPTIONS_H
