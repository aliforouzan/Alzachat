/*
 * Alzachat server AlzaServer class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_ALZASERVER_H
#define ALZACHAT_ALZASERVER_H

#include <QTcpServer>
#include <QThreadPool>
#include <QDebug>

class AlzaServer : public QTcpServer {
	Q_OBJECT
    public:
	explicit AlzaServer(QObject *parent = nullptr);
	void startServer();
	static void send(QTcpSocket *socket, QString *data);

    protected:

    signals:
	void dataReceived(QByteArray);

    private slots:
	void newConnection();
	void disconnected();
	void readyRead();

    private:
	QThreadPool *pool;
	QHash<QTcpSocket*, QByteArray*> buffers; //We need a buffer to store data until block has completely received
	QHash<QTcpSocket*, qint32*> sizes;	//We need to store the size to verify if a block has received completely

};


#endif //ALZACHAT_ALZASERVER_H
