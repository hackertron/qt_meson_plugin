#include "mesonbuildparser.h"
#include <utils/qtcprocess.h>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

MesonBuildParser::MesonBuildParser()
{

}

void MesonBuildParser::getprojectinfo()
{
    const QString meson = "/usr/local/bin/meson";
        //const QStringList args = {"introspect", "--targets", "/home/nightmare/practice/meson/builddir"};
        const QString args = "introspect --targets /home/nightmare/practice/meson/builddir/";

        QObject *parent = nullptr;
        Utils::QtcProcess *process = new Utils::QtcProcess(parent);

        //program->setProcessChannelMode(QProcess::ForwardedChannels);
        process->setCommand(meson, args);
        process->start();

        int res = process->waitForFinished();

        if ( !res ) {
            qDebug() << process->errorString();

        }
        process->waitForFinished();
        QByteArray output = process->readAllStandardOutput();
        qDebug() << output;

        const QJsonDocument doc = QJsonDocument::fromJson(output);
        qDebug().noquote() << doc;
        qDebug().noquote() << doc.array();
        foreach (auto value, doc.array()) {
            qDebug().noquote() << value;
            qDebug().noquote() << value.toObject();
            //qDebug().noquote() << value.toObject().value("name");
            qDebug().noquote() << "name : " << value.toObject().value("name").toString();
            //qDebug().noquote() << value.toObject().value("installed");
            qDebug().noquote() << "installed : " << value.toObject().value("installed").toBool();

            qDebug().noquote() << "id : " << value.toObject().value("id").toString();
            qDebug().noquote() << "filename : " << value.toObject().value("filename").toString();
        }


        QByteArray error = process->readAllStandardError();
        qDebug() << error;

    qDebug() << "meson call here";


}


