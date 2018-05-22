#pragma once

#include <QtGlobal>

#if defined(MESONPLUGIN_LIBRARY)
#  define MESONPLUGINSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MESONPLUGINSHARED_EXPORT Q_DECL_IMPORT
#endif
