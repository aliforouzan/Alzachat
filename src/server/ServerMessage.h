/*
 * Alzachat server ServerMessage class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_SERVERMESSAGE_H
#define ALZACHAT_SERVERMESSAGE_H

#include "Message.h"

class ServerMessage:Message {

    public:
	static int sendHello(void *data);
};


#endif //ALZACHAT_SERVERMESSAGE_H
