/*
 * Alzachat server header file.
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

    protected:
	void incomingConnection(qintptr handle) override;

    signals:

    public slots:

    private:
	QThreadPool *pool;
};


#endif //ALZACHAT_ALZASERVER_H
