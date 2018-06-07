/****************************************************************************
**
** Copyright (C) Jayaditya Gupta <cooljay.gupta@gmail.com>
** Contact: http://www.qt.io/licensing
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/
#include "mesonprojectmanagerplugin.h"
#include "mesonprojectmanagerconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <utils/mimetypes/mimedatabase.h>


#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>
#include <QFile>
#include <QObject>

#include "mesoncall.h"

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

    auto mesoncall = new QAction(tr("meson call"), this);
    Core::Command *cmd1 = Core::ActionManager::registerAction(mesoncall, Constants::MESON_CALL,Core::Context());

    cmd1->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+1")));
    connect(mesoncall, &QAction::triggered, this, &MesonProjectManagerPlugin::mesoncall);

    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("MesonProjectManager"));
    menu->addAction(cmd);
    menu->addAction(cmd1);
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


}

void MesonProjectManagerPlugin::mesoncall()
{
    MesonCall *meson = new MesonCall();
    connect(meson,SIGNAL(mesonProcess()),meson,SLOT(mesonProcessComplete()));

    meson->getProjectPath();
    meson->getProjectInfo();
    meson->getTargetInfo();
    meson->getBuildSystemFiles();
    delete meson;

}

} // namespace Internal
} // namespace MesonProjectManager
