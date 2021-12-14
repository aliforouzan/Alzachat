/*
 * Alzachat server main file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include <QCoreApplication>
#include "AlzaServer.h"
#include "ServerConfig.h"
#include "Logging.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	qInstallMessageHandler(alzaMessageHandler);

	AlzaServer Server;
	readConfig(DEV_CONF_FILE);
	validateConfig();
	Server.startServer();

	return app.exec();
}
