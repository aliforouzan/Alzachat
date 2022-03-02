/*
 * Alzachat client AlizaClient class definition.
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
#include <QBuffer>

#include "Alzachat.h"
#include "AlzaRunnable.h"
#include "User.h"

class AlzaClient : public QObject {
	Q_OBJECT
    public:
	explicit AlzaClient(QObject *parent, const QString &host, qint16 port);
	static int receive(void *socket);
	int send(QTcpSocket *socket, QString *data);
	QTcpSocket *getSocket() const;


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
	void result(int);

    private:
	QString host;
	qint16 port;
	QTcpSocket *socket;
	QTimer connectionTimer;

    public:
	User *me;
	static QByteArray byteArray;
};

#endif //ALZACHAT_ALZACLIENT_H
