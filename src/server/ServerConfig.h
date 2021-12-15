/*
 * Alzachat server ServerConfig class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_SERVERCONFIG_H
#define ALZACHAT_SERVERCONFIG_H

#include <string>
#include <vector>
#include <QSettings>
#include "User.h"

#define DEFAULT_CONF_FILE	"/etc/Alzachat/Alzachat.conf"
#define DEV_CONF_FILE		"/home/forouzan_a/codes/Alzachat/Alzachat.conf"

using namespace std;

struct serverConfig{
	QString ip;
	QString port;

	QString logLevel;
	QString logFile;
};

extern struct serverConfig config;

void readConfig(const QString&);
void validateConfig();

#endif //ALZACHAT_SERVERCONFIG_H
