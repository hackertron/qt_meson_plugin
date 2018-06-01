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

    QString getMesonPath();
    void getProjectInfo();
    void getBuildSystemFiles();
    void getTargetInfo();

};

#endif // MESONBUILDPARSER_H
