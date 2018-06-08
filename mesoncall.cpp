#include "mesoncall.h"
#include <utils/qtcprocess.h>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QFileDialog>
#include <QDir>

MesonCall::MesonCall(QObject *parent) : QObject(parent)
{

}

void MesonCall::mesonProcessComplete()
{
    qDebug() << "process complete";
}

QString MesonCall::getMesonPath()
{
    // get meson path from user here
    QString path = "/usr/local/bin/meson";
    return path;
}

QString MesonCall::getProjectPath()
{
    // select project here
    QString projectPath = "/home/nightmare/practice/meson/";

    return projectPath;

}

void MesonCall::getProjectInfo()
{

        const QString args = "introspect --projectinfo /home/nightmare/practice/meson/builddir/";

        QObject *parent = nullptr;
        Utils::QtcProcess *process = new Utils::QtcProcess(parent);
        process->setCommand(getMesonPath(), args);
        process->start();

        emit mesonProcess();

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

            projectInfoResults["name"] = value.toObject().value("name").toString();
            projectInfoResults["version"] = value.toObject().value("version").toString();
            projectInfoResults["subprojects"] = value.toObject().value("subversion");

        }


        QByteArray error = process->readAllStandardError();
        qDebug() << error;

}

void MesonCall::getBuildSystemFiles()
{
    // get build system files ( meson.build) here
    const QString args = "introspect --buildsystem-files /home/nightmare/practice/meson/builddir";
    QObject *parent = nullptr;
    Utils::QtcProcess *process = new Utils::QtcProcess(parent);

    process->setCommand(getMesonPath(),args);
    process->start();
    emit mesonProcess();

    QByteArray result  = process->readAllStandardOutput();
    qDebug() << result;



}

void MesonCall::getTargetInfo()
{
    const QString args = "introspect --targets /home/nightmare/practice/meson/builddir/";
    QObject *parent = nullptr;
    Utils::QtcProcess *process = new Utils::QtcProcess(parent);

    process->setCommand(getMesonPath(), args);
    process->start();
    emit mesonProcess();


    QByteArray output = process->readAllStandardOutput();
    qDebug() << output;

    const QJsonDocument doc = QJsonDocument::fromJson(output);
    foreach ( auto value, doc.array()) {
        introspectResults["name"] = value.toObject().value("name").toString();
        introspectResults["filename"] = value.toObject().value("filename").toString();
        introspectResults["id"] = value.toObject().value("id").toString();
        introspectResults["type"] = value.toObject().value("type").toString();
    }

}



