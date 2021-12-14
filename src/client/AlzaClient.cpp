/*
 * Alzachat client file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "AlzaClient.h"

AlzaClient::AlzaClient(QObject *parent, const QString &host, qint16 port) : QObject(parent) {
	QThreadPool::globalInstance()->setMaxThreadCount(5);
	socket = new QTcpSocket(parent);

	qDebug() << "A new socket created";

	connect(socket, SIGNAL(connected()), this, SLOT(connected()));
	connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
	connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
	connect(socket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
		this, SLOT(errorOccurred(QAbstractSocket::SocketError)));
	connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
		this, SLOT(stateChanged(QAbstractSocket::SocketState)));


	qDebug() << "Trying to connect to the server";
	socket->connectToHost( host, port );

	QAbstractSocket::SocketState s = socket->state();
	if (s == QAbstractSocket::BoundState)
		qDebug() << "Client connected at " + host + ":" + QString::number(port);
}


// asynchronous - runs separately from the thread we created
void AlzaClient::connected() {
	qDebug() << "Client connected event";
}

// asynchronous
void AlzaClient::disconnected() {
	qDebug() << "Client disconnected";
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
	connect(mytask, SIGNAL(Result(int)), this, SLOT(TaskResult(int)), Qt::QueuedConnection);

	qDebug() << "Starting a new task using a thread from the QThreadPool";
	QThreadPool::globalInstance()->start(mytask);

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
