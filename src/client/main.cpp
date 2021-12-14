/*
 * Alzachat client main file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include <QCoreApplication>
#include "Logging.h"
#include "AlzaClient.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	qInstallMessageHandler(alzaMessageHandler);

	AlzaClient client(&app, "localhost", 1234);

	return app.exec();
}