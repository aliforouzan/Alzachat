/*
 * Alzachat lib VoiceMessage class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_VOICEMESSAGE_H
#define ALZACHAT_VOICEMESSAGE_H

#include "MediaMessage.h"

class VoiceMessage:MediaMessage {
	int send() override;
};


#endif //ALZACHAT_VOICEMESSAGE_H
