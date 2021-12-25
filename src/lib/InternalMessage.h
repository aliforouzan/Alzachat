/*
 * Alzachat lib InternalMessage class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_INTERNALMESSAGE_H
#define ALZACHAT_INTERNALMESSAGE_H

#include "Alzachat.h"
#include "Message.h"

struct registerMessageContent {
	QString idStr = "id=";
	id_t id;
	QString usernameStr = "username=";
	QString username;
	QString passwordStr = "password=";
	QString password;
	QString firstAndFamilyNameStr = "firstAndFamilyName=";
	QString firstAndFamilyName;
	QString phoneNumberStr = "phoneNumber=";
	qint64 phoneNumber;
};

class InternalMessage:Message {
    public:
	static QString *registerMessageContentToQString(struct registerMessageContent &content) {
		return new QString(content.idStr + QString::number(content.id) + content.usernameStr +
			content.username + content.passwordStr + content.password + content.firstAndFamilyNameStr +
			content.firstAndFamilyName + content.phoneNumberStr + QString::number(content.phoneNumber));
	}
};

#endif //ALZACHAT_INTERNALMESSAGE_H
