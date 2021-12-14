/*
 * Alzachat server config reader file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include <QCoreApplication>
#include <QHostAddress>
#include "Alzachat.h"
#include "ServerConfig.h"

struct serverConfig config;

void readConfig(const QString& path)
{
	qDebug() << "Server configs will read from " + path;

	auto * configRead = new QSettings(path ,QSettings::NativeFormat);
	config.ip = configRead->value("connection/ip").toString();
	config.port = configRead->value("connection/port").toString();

	config.logLevel = configRead->value("logging/logLevel").toString();
	config.logFile = configRead->value("logging/logFile").toString();

	delete configRead;
}

void validateConfig()
{
	QHostAddress addr;
	short port;

	if (config.ip.isNull() || config.port.isNull())
		qFatal("Ip address and port number not defined in config file");

	if (!addr.setAddress(config.ip))
		qFatal("Bad ip address");

	port = config.port.toShort();
	if (port <= 0)
		qFatal("Bad port number");
}