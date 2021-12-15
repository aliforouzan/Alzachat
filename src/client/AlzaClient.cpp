/*
 * Alzachat client AlizaClient class implementation.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "AlzaClient.h"

AlzaClient::AlzaClient(QObject *parent, const QString &host, qint16 port) : QObject(parent) {

	this->host = host;
	this->port = port;
	connectionTimer.setInterval(1000);

	QThreadPool::globalInstance()->setMaxThreadCount(5);
	socket = new QTcpSocket(parent);

	qDebug() << "A new socket created";

	QAbstractSocket::connect(socket, SIGNAL(connected()), this, SLOT(connected()));
	QAbstractSocket::connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
	QAbstractSocket::connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
	QAbstractSocket::connect(socket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
		this, SLOT(errorOccurred(QAbstractSocket::SocketError)));
	QAbstractSocket::connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
		this, SLOT(stateChanged(QAbstractSocket::SocketState)));
	QAbstractSocket::connect(&connectionTimer, &QTimer::timeout, this, &AlzaClient::connect);

	connect();
}

void AlzaClient::connect() {
	qDebug() << "Trying to connect to the server " + host + ":" + QString::number(port);
	socket->connectToHost(host,port);
}


// asynchronous - runs separately from the thread we created
void AlzaClient::connected() {
	qDebug() << "Client connected";
	connectionTimer.setInterval(1000);
	connectionTimer.stop();
}

// asynchronous
void AlzaClient::disconnected() {
	qDebug() << "Client disconnected";
}

// After a task performed a time consuming task.
// We grab the result here, and send it to client
void AlzaClient::TaskResult(int Number) {
	QByteArray Buffer;
	Buffer.append("\r\nTask result = %d", Number);

	socket->write(Buffer);
}

void AlzaClient::errorOccurred(QAbstractSocket::SocketError error) {
	qCritical() << "error in connection: " + socket->errorString();

	connectionTimer.setSingleShot(true);
	connectionTimer.setInterval(connectionTimer.interval()*2);

	qDebug() << "retry in " << (connectionTimer.interval()/1000) << "second(s)";

	connectionTimer.start();
}

void AlzaClient::stateChanged(QAbstractSocket::SocketState socketState) {

	QString state;

	switch (socketState) {
		case QAbstractSocket::BoundState:
			state = "BoundState";
			break;
		case QAbstractSocket::ConnectedState:
			state = "ConnectedState";
			break;
		case QAbstractSocket::ClosingState:
			state = "ClosingState";
			break;
		case QAbstractSocket::ConnectingState:
			state = "ConnectingState";
			break;
		case QAbstractSocket::HostLookupState:
			state = "HostLookupState";
			break;
		case QAbstractSocket::UnconnectedState:
			state = "UnconnectedState";
			break;
		case QAbstractSocket::ListeningState:
			state = "ListeningState";
			break;
	}

	qDebug() << "connection state change to " + state;
}

// Our main thread of execution
// This happening via main thread
// Our code running in our thread not in Qthread
// That's why we're getting the thread from the pool

void AlzaClient::readyRead() {
	qDebug() << "MyClient::readyRead()";
	qDebug() << socket->readAll();

	// Time consumer
	AlzaRunnable *mytask = new AlzaRunnable();
	mytask->setAutoDelete(true);
	QAbstractSocket::connect(mytask, SIGNAL(Result(int)), this, SLOT(TaskResult(int)), Qt::QueuedConnection);

	qDebug() << "Starting a new task using a thread from the QThreadPool";
	QThreadPool::globalInstance()->start(mytask);

}
