/*
 * Alzachat lib Message class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_MESSAGE_H
#define ALZACHAT_MESSAGE_H

#include <QRegularExpression>
#include "User.h"

enum MESSAGE_CMD
{
	HELLO,			/* HELLO message: client<- server : connection establishment confirmation from server */
	OK,			/* Ok message:    client<->server : positive response for a request */
	NOK,			/* Nok message:   client<->server : negative response for a request */
	ALIVE,			/* Alive message: client ->server : retrieve new message and hold connection open */
	REGISTER,
	AUTH,
	TWO_STEP_AUTH,
	REGULAR,
	USER_STATUS,
	GET_UNREAD_MESSAGE,
	SEARCH_USER
};

class Message {
private:
	MESSAGE_CMD cmd;
	id_t sender;
	id_t receiver;
	size_t contentLength;
	QString *content;

public:
	Message(MESSAGE_CMD cmd, id_t sender, id_t receiver) :
	cmd(cmd), sender(sender), receiver(receiver) { contentLength = 0; };

	Message(MESSAGE_CMD cmd, id_t sender, id_t receiver, qsizetype contentLength, QString *content) :
	cmd(cmd), sender(sender), receiver(receiver), contentLength(contentLength), content(content) {};

	static QString *MessageHeaderToQString(struct Message &msg) {
		return new QString("cmd=" + QString::number(msg.cmd) + "sender=" + QString::number(msg.sender) +
					   "receiver=" + QString::number(msg.receiver) + "contentLength=" + QString::number(msg.contentLength));
	}

	static struct Message *QStringToMessageHeader(QString &msg) {
		QRegularExpression re("cmd=\\d+sender=\\d+receiver=\\d+contentLength=\\d+$");
		QRegularExpressionMatch match = re.match(msg);
		if (re.captureCount() == 3) {
			return new Message(static_cast<MESSAGE_CMD>(match.captured(1).toInt()),
						       match.captured(2).toUInt(), match.captured(2).toUInt());
		}

		return nullptr;
	}
};


#endif //ALZACHAT_MESSAGE_H
