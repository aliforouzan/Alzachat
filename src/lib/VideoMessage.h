/*
 * Alzachat lib VideoMessage class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_VIDEOMESSAGE_H
#define ALZACHAT_VIDEOMESSAGE_H

#include "MediaMessage.h"

class VideoMessage:MediaMessage {
	int send() override;
};


#endif //ALZACHAT_VIDEOMESSAGE_H
