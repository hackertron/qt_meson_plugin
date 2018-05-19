#pragma once

#include <QtGlobal>

#if defined(MYPLUGIN_LIBRARY)
#  define MYPLUGINSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MYPLUGINSHARED_EXPORT Q_DECL_IMPORT
#endif
