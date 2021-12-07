//
// Created by forouzan_a on 11/29/21.
//

#ifndef ALZACHAT_VOICEMESSAGE_H
#define ALZACHAT_VOICEMESSAGE_H

#include "MediaMessage.h"

class VoiceMessage:MediaMessage {
	int send() override;
};


#endif //ALZACHAT_VOICEMESSAGE_H
