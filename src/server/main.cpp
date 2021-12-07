/*
 * Alzachat server main file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include <QCoreApplication>
#include "AlzaServer.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	AlzaServer Server;
	Server.startServer();

	return a.exec();
}
