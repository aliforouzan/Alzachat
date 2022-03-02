/*
 * Alzachat client ClientMessage class implementation.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "AlzaRunnable.h"
#include "AlzaClient.h"
#include "ClientMessage.h"

int ClientMessage::sendHello(AlzaClient &client) {
	Message msg(MESSAGE_CMD::HELLO, client.me->getId(), 0);
	QString *msgStr = Message::MessageHeaderToQString(msg);
	client.send(client.getSocket(), msgStr);
	delete(msgStr);

	qDebug() << "ajab!!!!";
}
