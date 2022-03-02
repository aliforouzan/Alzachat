/*
 * Alzachat server AlzaServer class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_ALZASERVER_H
#define ALZACHAT_ALZASERVER_H

#include <QTcpServer>
#include <QThreadPool>
#include "Alzachat.h"

class AlzaServer : public QTcpServer {
	Q_OBJECT
    public:
	explicit AlzaServer(QObject *parent = nullptr);
	void startServer();
	static void send(qintptr socketDescriptor, QString *data);

    protected:
	void incomingConnection(qintptr handle) override;
    signals:
	/*void dataReceived(QByteArray);*/

    private slots:
	void result(int);
	/*void newConnection();
	void disconnected();
	void readyRead();*/

    private:
	QThreadPool *pool;
	QHash<id_t, qintptr> connections;
	QHash<id_t, User*> users;
    public:
	const QHash<id_t, qintptr> &getConnections() const;

	const QHash<id_t, User *> &getUsers() const;
	//QHash<QTcpSocket*, qint32*> sizes;	//We need to store the size to verify if a block has received completely

};

extern AlzaServer *server;

#endif //ALZACHAT_ALZASERVER_H
