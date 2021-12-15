/*
 * Alzachat lib TextMessage class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_TEXTMESSAGE_H
#define ALZACHAT_TEXTMESSAGE_H

#include "Message.h"

class TextMessage:Message {
	int send() override;
	int receive() override;
};


#endif //ALZACHAT_TEXTMESSAGE_H
