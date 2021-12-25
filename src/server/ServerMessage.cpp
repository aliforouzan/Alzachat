/*
 * Alzachat server ServerMessage class implementation.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "AlzaServer.h"
#include "InternalMessage.h"
#include "ServerMessage.h"

int ServerMessage::sendHello(void *socketDescriptor) {
	Message msg(MESSAGE_CMD::HELLO, 0, 0);
	QString *msgStr = Message::MessageHeaderToQString(msg);
	AlzaServer::send(static_cast<QTcpSocket *>(socketDescriptor), msgStr);
	delete(msgStr);
}
