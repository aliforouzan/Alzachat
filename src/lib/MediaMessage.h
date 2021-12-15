/*
 * Alzachat lib MediaMessage class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */
#ifndef ALZACHAT_MEDIAMESSAGE_H
#define ALZACHAT_MEDIAMESSAGE_H

#include <streambuf>
#include "Message.h"

class MediaMessage:Message {
private:
	streambuf stream;
public:
	int send() override;
};


#endif //ALZACHAT_MEDIAMESSAGE_H
