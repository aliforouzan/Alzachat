/*
 * Alzachat lib logging class implementation.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "Alzachat.h"
#include "Logging.h"

void alzaMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	QByteArray localMsg = msg.toLocal8Bit();
	switch (type) {
		case QtDebugMsg:
			fprintf(stderr, "Debug (%s): %s (%s:%u, %s)\n", qPrintable(QTime::currentTime().toString("hh:mm:ss.zzz")),
				localMsg.constData(), context.file, context.line, context.function);
			break;
		case QtInfoMsg:
			fprintf(stderr, "Info (%s): %s\n",
				qPrintable(QTime::currentTime().toString("hh:mm:ss.zzz")), localMsg.constData());
			break;
		case QtWarningMsg:
			fprintf(stderr, "Warning (%s): %s\n",
				qPrintable(QTime::currentTime().toString("hh:mm:ss.zzz")), localMsg.constData());
			break;
		case QtCriticalMsg:
			fprintf(stderr, "Critical (%s): %s\n",
				qPrintable(QTime::currentTime().toString("hh:mm:ss.zzz")), localMsg.constData());
			break;
		case QtFatalMsg:
			fprintf(stderr, "Fatal (%s): %s\n",
				qPrintable(QTime::currentTime().toString("hh:mm:ss.zzz")), localMsg.constData());
			abort();
	}
}