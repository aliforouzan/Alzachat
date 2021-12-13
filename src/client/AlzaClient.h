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
	explicit AlzaClient(QObject *parent = 0);
	void SetSocket(int Descriptor);

    signals:

    public slots:
	void connected();
	void disconnected();
	void readyRead();

	// make the server fully ascynchronous
	// by doing time consuming task
	void TaskResult(int Number);

    private:
	QTcpSocket *socket;
};


#endif //ALZACHAT_ALZACLIENT_H
