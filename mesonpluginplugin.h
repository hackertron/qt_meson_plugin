#pragma once

#include "mesonplugin_global.h"

#include <extensionsystem/iplugin.h>

namespace mesonplugin {
namespace Internal {

class mesonpluginPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "mesonplugin.json")

public:
    mesonpluginPlugin();
    ~mesonpluginPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private:
    void triggerAction();
};

} // namespace Internal
} // namespace mesonplugin
