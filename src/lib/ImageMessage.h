/*
 * Alzachat lib ImageMessage class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_IMAGEMESSAGE_H
#define ALZACHAT_IMAGEMESSAGE_H

#include "MediaMessage.h"

class ImageMessage:MediaMessage {
	int send() override;
};


#endif //ALZACHAT_IMAGEMESSAGE_H
