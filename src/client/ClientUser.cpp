/*
 * Alzachat client ClientUser class implementation.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "InternalMessage.h"
#include "ClientUser.h"

void ClientUser::userRegister() {
	struct registerMessageContent msgContent = {.id = getId(), .username = getUsername(), .password = getPassword(),
		.firstAndFamilyName = getFirstAndFamilyName(), .phoneNumber = getPhoneNumber()};
	QString *msgContentStr = InternalMessage::registerMessageContentToQString(msgContent);
	Message *msg = new Message(MESSAGE_CMD::REGISTER, 0, 0, msgContentStr->length(), msgContentStr);
}
