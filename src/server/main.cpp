/*
 * Alzachat server main file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include <QCoreApplication>
#include "AlzaServer.h"
#include "ServerConfig.h"
#include "Logging.h"

AlzaServer *server;

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	qInstallMessageHandler(alzaMessageHandler);

	server = new AlzaServer();
	readConfig(DEV_CONF_FILE);
	validateConfig();
	server->startServer();

	return app.exec();
}
