/*
 * Alzachat server file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "serverRunnable.h"
#include "ServerConfig.h"
#include "AlzaServer.h"

vector<User> sysUser;

AlzaServer::AlzaServer(QObject *parent) : QTcpServer(parent) {
	pool = new QThreadPool(this);
	pool->setMaxThreadCount(5);
}

void AlzaServer::startServer() {
	if(this->listen(QHostAddress(config.ip), config.port.toShort()))
		qDebug() << "Server started on Address: " + config.ip + " port " + config.port;
	else
		qFatal("starting server failed!");
}

void AlzaServer::incomingConnection(qintptr handle) {
	// 1. QTcpServer gets a new connection request from a client.
	// 2. It makes a task (runnable) here.
	// 3. Then, the server grabs one of the threads.
	// 4. The server throws the runnable to the thread.

	// Note: Rannable is a task not a thread
	auto *task = new serverRunnable();
	task->setAutoDelete(true);

	task->socketDescriptor = handle;

	pool->start(task);
	qDebug() << "pool started";
}