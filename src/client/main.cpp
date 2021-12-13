/*
 * Alzachat client main file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include <QCoreApplication>
#include "../lib/Logging.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	qInstallMessageHandler(alzaMessageHandler);



	return app.exec();
}