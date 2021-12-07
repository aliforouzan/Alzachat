//
// Created by forouzan_a on 11/29/21.
//

#ifndef ALZACHAT_TEXTMESSAGE_H
#define ALZACHAT_TEXTMESSAGE_H

#include "Message.h"

class TextMessage:Message {
	int send() override;
	int receive() override;
};


#endif //ALZACHAT_TEXTMESSAGE_H
