/*
 * Alzachat server AlzaServer class implementation.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include <QRandomGenerator>
#include "AlzaRunnable.h"
#include "ServerConfig.h"
#include "ServerMessage.h"
#include "AlzaServer.h"

vector<User> sysUser;
extern AlzaServer *server;

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

void AlzaServer::incomingConnection(qintptr handle)
{
	id_t userId;
	User *user;

	do {
		userId = QRandomGenerator::global()->generate();
	} while (connections.contains(userId));

	user = new User(userId);
	connections.insert(userId, handle);
	users.insert(userId, user);
	auto *task = new AlzaRunnable(ServerMessage::sendHello, reinterpret_cast<void *>(user), this);
	pool->start(task);
}

void AlzaServer::result(int returnValue) {
	qDebug() << "Task result = " << returnValue;
}

/*void AlzaServer::disconnected()
{
	QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
	QByteArray *buffer = buffers.value(socket);
	qint32 *s = sizes.value(socket);
	socket->deleteLater();
	delete buffer;
	delete s;
}*/

qint32 ArrayToInt(QByteArray source)
{
	qint32 temp;
	QDataStream data(&source, QIODevice::ReadWrite);
	data >> temp;
	return temp;
}

/*void AlzaServer::readyRead()
{
	QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
	QByteArray *buffer = buffers.value(socket);
	qint32 *s = sizes.value(socket);
	qint32 size = *s;
	while (socket->bytesAvailable() > 0)
	{
		buffer->append(socket->readAll());
		while ((size == 0 && buffer->size() >= 4) || (size > 0 && buffer->size() >= size)) //While can process data, process it
		{
			if (size == 0 && buffer->size() >= 4) //if size of data has received completely, then store it on our global variable
			{
				size = ArrayToInt(buffer->mid(0, 4));
				*s = size;
				buffer->remove(0, 4);
			}
			if (size > 0 && buffer->size() >= size) // If data has received completely, then emit our SIGNAL with the data
			{
				QByteArray data = buffer->mid(0, size);
				buffer->remove(0, size);
				size = 0;
				*s = size;
				emit dataReceived(data);
			}
		}
	}
}*/

void AlzaServer::send(qintptr socketDescriptor, QString *data) {
	QTcpSocket *socket= new QTcpSocket;

	socket->setSocketDescriptor(socketDescriptor);
	server->addPendingConnection(socket);
	socket->write(data->toUtf8());
	socket->flush();
	socket->waitForBytesWritten();
}

const QHash<id_t, qintptr> &AlzaServer::getConnections() const {
	return connections;
}

const QHash<id_t, User *> &AlzaServer::getUsers() const {
	return users;
}
