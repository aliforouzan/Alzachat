/*
 * Alzachat server AlzaServer class implementation.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "AlzaRunnable.h"
#include "ServerConfig.h"
#include "ServerMessage.h"
#include "AlzaServer.h"

vector<User> sysUser;

AlzaServer::AlzaServer(QObject *parent) : QTcpServer(parent) {
	pool = new QThreadPool(this);
	pool->setMaxThreadCount(5);
	connect(this, SIGNAL(newConnection()), SLOT(newConnection()));
}

void AlzaServer::startServer() {
	if(this->listen(QHostAddress(config.ip), config.port.toShort()))
		qDebug() << "Server started on Address: " + config.ip + " port " + config.port;
	else
		qFatal("starting server failed!");
}

void AlzaServer::newConnection()
{
	while (this->hasPendingConnections()) {
		QTcpSocket *socket = this->nextPendingConnection();
		connect(socket, SIGNAL(readyRead()), SLOT(readyRead()));
		connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
		auto *buffer = new QByteArray();
		auto *s = new qint32(0);
		buffers.insert(socket, buffer);
		sizes.insert(socket, s);

		if (socket->state() == QAbstractSocket::ConnectedState) {
			auto *task = new AlzaRunnable(ServerMessage::sendHello, socket, true, this);
			pool->start(task);
			//delete(task);
		}
	}
}

void AlzaServer::disconnected()
{
	QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
	QByteArray *buffer = buffers.value(socket);
	qint32 *s = sizes.value(socket);
	socket->deleteLater();
	delete buffer;
	delete s;
}


qint32 ArrayToInt(QByteArray source)
{
	qint32 temp;
	QDataStream data(&source, QIODevice::ReadWrite);
	data >> temp;
	return temp;
}

void AlzaServer::readyRead()
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
}

void AlzaServer::send(QTcpSocket *socket, QString *data) {
	socket->write(data->toUtf8());
	socket->flush();
	socket->waitForBytesWritten();
}
