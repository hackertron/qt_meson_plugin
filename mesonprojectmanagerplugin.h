#pragma once

#include "mesonprojectmanager_global.h"

#include <extensionsystem/iplugin.h>

#include <QVariantMap>

namespace MesonProjectManager {
namespace Internal {

class MesonProjectManagerPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "MesonProjectManager.json")

public:
    MesonProjectManagerPlugin();
    ~MesonProjectManagerPlugin();

    QVariantMap mesoninfo;

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private:
    void triggerAction();
    void mesoncall();
};

} // namespace Internal
} // namespace MesonProjectManager
