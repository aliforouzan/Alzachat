/*
 * Alzachat client file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "AlzaClient.h"

AlzaClient::AlzaClient(QObject *parent) :
	QObject(parent)
{
	QThreadPool::globalInstance()->setMaxThreadCount(5);
}

void AlzaClient::SetSocket(int Descriptor)
{
	// make a new socket
	socket = new QTcpSocket(this);

	qDebug() << "A new socket created!";

	connect(socket, SIGNAL(connected()), this, SLOT(connected()));
	connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
	connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

	socket->setSocketDescriptor(Descriptor);

	qDebug() << " Client connected at " << Descriptor;
}


// asynchronous - runs separately from the thread we created
void AlzaClient::connected()
{
	qDebug() << "Client connected event";
}

// asynchronous
void AlzaClient::disconnected()
{
	qDebug() << "Client disconnected";
}

// Our main thread of execution
// This happening via main thread
// Our code running in our thread not in Qthread
// That's why we're getting the thread from the pool

void AlzaClient::readyRead()
{
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
void AlzaClient::TaskResult(int Number)
{
	QByteArray Buffer;
	Buffer.append("\r\nTask result = %d", Number);

	socket->write(Buffer);
}