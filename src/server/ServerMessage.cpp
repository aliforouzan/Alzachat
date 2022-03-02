/*
 * Alzachat server ServerMessage class implementation.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "AlzaServer.h"
#include "InternalMessage.h"
#include "ServerMessage.h"

int ServerMessage::sendHello(void *user) {
	Message msg(MESSAGE_CMD::HELLO, 0, ((User *)user)->getId());
	QString *msgStr = Message::MessageHeaderToQString(msg);
	AlzaServer::send(server->getConnections().find(((User *)user)->getId()).value(), msgStr);
	delete(msgStr);

	qDebug() << "ajab!!!!";
}
