/*
 * Alzachat Runnable header file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_ALZARUNNABLE_H
#define ALZACHAT_ALZARUNNABLE_H


#include <QRunnable>
#include <QTcpSocket>

class AlzaRunnable : public QRunnable {
    public:
	AlzaRunnable();

    protected:
	void run();

    public:
	qintptr socketDescriptor;

};


#endif //ALZACHAT_ALZARUNNABLE_H
