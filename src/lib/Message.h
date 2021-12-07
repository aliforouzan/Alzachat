//
// Created by forouzan_a on 11/29/21.
//

#ifndef ALZACHAT_MESSAGE_H
#define ALZACHAT_MESSAGE_H

#include "../server/User.h"

enum class MESSAGE_CMD
{
	M1,
	M2
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
