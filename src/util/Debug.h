#ifndef DEBUG_H
#define DEBUG_H

#include <QDebug>

namespace Debug {
	namespace {
			const QString kLogKey = "debug/log";
			static bool logging = false;
	}
	void setLogging(bool log) {
		logging = log;
		QSettings().setValue(kLogKey, enable);
	}
	
	bool isLogging() {
		logging = QSettings().value(kLogKey).toBool();
		return logging;
	}
};

#ifdef DEBUG_OUTPUT_GENERAL
#define Debug(x)                                                               \
  do {                                                                         \
    if (logging) \
		qDebug() << x;                                                             \
  } while (false)
#else
#define Debug(x)
#endif

#ifdef DEBUG_OUTPUT_REFRESH
#define DebugRefresh(x)                                                        \
  do {                                                                         \
    if (logging) \
		qDebug() << Q_FUNC_INFO << QStringLiteral(": ") << x;                  \
  } while (false)
#else
#define DebugRefresh(x)
#endif
#endif // DEBUG_H
