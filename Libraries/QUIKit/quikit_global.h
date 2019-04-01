#ifndef QUIKIT_GLOBAL_H
#define QUIKIT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QUIKIT_LIBRARY)
#  define QUIKITSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QUIKITSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QUIKIT_GLOBAL_H
