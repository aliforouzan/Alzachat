/*
 * Alzachat lib Message file.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "Message.h"

Message::Message(MESSAGE_CMD cmd, id_t sender, id_t receiver) :
	cmd(cmd), sender(sender), receiver(receiver) {}

Message::Message(MESSAGE_CMD cmd, id_t sender, id_t receiver, size_t contentLength, string &content) :
	cmd(cmd), sender(sender), receiver(receiver), contentLength(contentLength), content(content) {}

int Message::send() {
	return 0;
}

int Message::receive() {
	return 0;
}