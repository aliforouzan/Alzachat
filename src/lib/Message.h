/*
 * Alzachat lib Message file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_MESSAGE_H
#define ALZACHAT_MESSAGE_H

#include "../src/server/User.h"

enum class MESSAGE_CMD
{
	ALIVE,
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
	string content;

public:
	Message(MESSAGE_CMD cmd, id_t sender, id_t receiver);
	Message(MESSAGE_CMD cmd, id_t sender, id_t receiver, size_t contentLength, string &content);

	virtual int send();
	virtual int receive();
};


#endif //ALZACHAT_MESSAGE_H
