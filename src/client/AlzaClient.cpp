/*
 * Alzachat client AlizaClient class implementation.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include <QRandomGenerator>
#include "AlzaClient.h"
#include "ClientMessage.h"

AlzaClient::AlzaClient(QObject *parent, const QString &host, qint16 port) : QObject(parent) {

	this->host = host;
	this->port = port;
	connectionTimer.setInterval(1000);
	me = new User(QRandomGenerator::global()->generate());

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
	socket->setSocketOption(QAbstractSocket::KeepAliveOption, 1);

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

	auto task = new AlzaRunnable(receive, static_cast<void *>(socket), this);
	QThreadPool::globalInstance()->start(task);
}

// After a task performed a time consuming task.
// We grab the result here, and send it to client
void AlzaClient::result(int returnValue) {
	qDebug() << "Task result = " << returnValue;
}

int AlzaClient::receive(void *socket) {
	/*QDataStream in((QTcpSocket *)socket);
	QString msgString;

	in.startTransaction();
	QString str;
	qint32 a;
	in >> str >> a; // try to read packet atomically

	if (!in.commitTransaction())
		return 1;*/

	byteArray = ((QTcpSocket *)socket)->readAll();

	qDebug() << byteArray;

}

int AlzaClient::send(QTcpSocket *socket, QString *data) {
	qDebug() << "trying to send new message:" << data;
	socket->write(data->toUtf8());
	socket->flush();
	socket->waitForBytesWritten();
	qDebug() << "message was successfully sent." << data;
}

QTcpSocket *AlzaClient::getSocket() const {
	return socket;
}
