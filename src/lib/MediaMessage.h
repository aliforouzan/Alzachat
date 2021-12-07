//
// Created by forouzan_a on 11/29/21.
//

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
