#ifndef MESONBUILDPARSER_H
#define MESONBUILDPARSER_H


#include <QJsonDocument>
#include <QJsonArray>
#include <QVariantMap>


class MesonBuildParser
{
public:
    MesonBuildParser();
    QVariantMap projectInfoResults;
    QVariantMap introspectResults;
    QString projectPath;



    QString getMesonPath();
    QString getProjectPath();
    void getProjectInfo();
    void getBuildSystemFiles();
    void getTargetInfo();

};

#endif // MESONBUILDPARSER_H
