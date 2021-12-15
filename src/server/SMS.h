/*
 * Alzachat server SMS class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#ifndef ALZACHAT_SMS_H
#define ALZACHAT_SMS_H

#include <string>

using namespace std;

class SMS {
private:
	uint64_t to;
	string content;

public:
	SMS(uint64_t to, const string &content);
};


#endif //ALZACHAT_SMS_H
