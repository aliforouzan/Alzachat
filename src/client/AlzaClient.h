/*
 * Alzachat client header file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_ALZACLIENT_H
#define ALZACHAT_ALZACLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QThreadPool>
#include <QTimer>
#include <QDebug>

#include "Alzachat.h"
#include "ServerRunnable.h"

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
	void connect();
	void stateChanged(QAbstractSocket::SocketState socketState);

	// make the server fully ascynchronous
	// by doing time consuming task
	void TaskResult(int Number);

    private:
	QString host;
	qint16 port;
	QTcpSocket *socket;
	QTimer connectionTimer;
};


#endif //ALZACHAT_ALZACLIENT_H
