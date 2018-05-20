#pragma once

#include <QtGlobal>

#if defined(QT_MESON_PLUGIN_LIBRARY)
#  define QT_MESON_PLUGINSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QT_MESON_PLUGINSHARED_EXPORT Q_DECL_IMPORT
#endif
