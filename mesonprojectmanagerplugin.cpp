#include "mesonprojectmanagerplugin.h"
#include "mesonprojectmanagerconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

#include <utils/qtcprocess.h>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>

namespace MesonProjectManager {
namespace Internal {

MesonProjectManagerPlugin::MesonProjectManagerPlugin()
{
    // Create your members
}

MesonProjectManagerPlugin::~MesonProjectManagerPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool MesonProjectManagerPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.

    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    auto action = new QAction(tr("MesonProjectManager Action"), this);
    Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
                                                             Core::Context(Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
    connect(action, &QAction::triggered, this, &MesonProjectManagerPlugin::triggerAction);

    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("MesonProjectManager"));
    menu->addAction(cmd);
    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    return true;
}

void MesonProjectManagerPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag MesonProjectManagerPlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

void MesonProjectManagerPlugin::triggerAction()
{
    QMessageBox::information(Core::ICore::mainWindow(),
                             tr("Action Triggered"),
                             tr("This is an action from MesonProjectManager."));

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

}

} // namespace Internal
} // namespace MesonProjectManager
