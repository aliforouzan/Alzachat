/*
 * Alzachat server SMS class implementation.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "SMS.h"

SMS::SMS(uint64_t to, const string &content) : to(to), content(content) {}
