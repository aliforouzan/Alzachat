/*
 * Alzachat Runnable file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "AlzaRunnable.h"

AlzaRunnable::AlzaRunnable()
{
}

void AlzaRunnable::run()
{
	if(!socketDescriptor) return;

	QTcpSocket socket;
	socket.setSocketDescriptor(socketDescriptor);

	socket.write("From server: hello world");
	socket.flush();
	socket.waitForBytesWritten();
	socket.close();
}