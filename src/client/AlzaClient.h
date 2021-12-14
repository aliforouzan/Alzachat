/*
 * Alzachat client header file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_ALZACLIENT_H
#define ALZACHAT_ALZACLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThreadPool>
#include "../lib/AlzaRunnable.h"
#include "../lib/Alzachat.h"

class AlzaClient : public QObject {
	Q_OBJECT
    public:
	explicit AlzaClient(QObject *parent, const QString &host, qint16 port);

    signals:

    public slots:
	void connected();
	void disconnected();
	void readyRead();
	void errorOccurred(QAbstractSocket::SocketError error);
	void stateChanged(QAbstractSocket::SocketState socketState);

	// make the server fully ascynchronous
	// by doing time consuming task
	void TaskResult(int Number);

    private:
	QTcpSocket *socket;
};


#endif //ALZACHAT_ALZACLIENT_H
