#pragma once

#include "qt_meson_plugin_global.h"

#include <extensionsystem/iplugin.h>

namespace qt_meson_plugin {
namespace Internal {

class qt_meson_pluginPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "qt_meson_plugin.json")

public:
    qt_meson_pluginPlugin();
    ~qt_meson_pluginPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private:
    void triggerAction();
};

} // namespace Internal
} // namespace qt_meson_plugin
