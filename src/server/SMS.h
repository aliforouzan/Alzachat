//
// Created by forouzan_a on 11/29/21.
//

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
