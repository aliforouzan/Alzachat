/*
 * Alzachat Runnable file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "serverRunnable.h"

serverRunnable::serverRunnable() {
	qDebug() << "MyTask()";
}

// When the thread pool kicks up, and implements Qrunnable
// it's going to hit this run, and it's going to do this time consuming task.
// After it's done, we're going to send the results back to our main thread.
// This runs in the separate thread, and we do not have any control over this thread,
// but Qt does.
// This may just stay in the queue for several ms depending on how busy the server is.

void serverRunnable::run() {
	qDebug() << "Task start";

	int iNumber = 0;
	for(int i = 0; i < 100; i++)
	{
		iNumber += 1;
	}

	qDebug() << "Task done";
	emit Result(iNumber);
}