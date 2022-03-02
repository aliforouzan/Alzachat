/*
 * Alzachat lib runnable class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_ALZARUNNABLE_H
#define ALZACHAT_ALZARUNNABLE_H


#include <QRunnable>
#include <QTcpSocket>


// Q_OBJECT missing in the original file generated by class wizard.
// because we set this class with base class QRunnable
// with no inheritance in the class wizard
// We do not have this. So, we cannot use signal/slot
// But we need them.
// Thus, we should use multiple inheritance: QObject inserted here

class AlzaRunnable : public QObject, public QRunnable {
	Q_OBJECT
    public:
	AlzaRunnable(int (*func)(void *), void *funcData,
		     QObject *parent = nullptr, bool autoDelete = true) :
		     func(func), funcData(funcData), QObject(parent) {
		setAutoDelete(autoDelete);
		QAbstractSocket::connect(this, SIGNAL(result(int)), parent, SLOT(result(int)));
	};

    private:
	int (*func)(void *);
	void *funcData;

    signals:
	// notify to the main thread when we're done
	void result(int Number);

    protected:
	void run() override {
		qDebug() << "runnable started func:" << &func << "data_ptr:" << funcData;
		emit result(func(funcData));
		qDebug() << "runnable finished func:" << &func << "data_ptr:" << funcData;
	};

};


#endif //ALZACHAT_ALZARUNNABLE_H
