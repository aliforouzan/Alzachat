/*
 * Alzachat client ClientMessage class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */


#ifndef ALZACHAT_CLIENTMESSAGE_H
#define ALZACHAT_CLIENTMESSAGE_H

#include "Message.h"

class ClientMessage:Message {
    public:
	int send();
};


#endif //ALZACHAT_CLIENTMESSAGE_H
