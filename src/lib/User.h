/*
 * Alzachat lib User class definition.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */
#ifndef ALZACHAT_USER_H
#define ALZACHAT_USER_H

#include <vector>
#include "Alzachat.h"

using namespace std;

#define MAX_USERNAME_LEN	80
#define MAX_PASSWORD_LEN	80

class User {
private:
	id_t id;
	QString username;
	QString password;
	QString firstAndFamilyName;
	qint64 phoneNumber;
	vector<User *> friends;
public:
	User(id_t id, QString &username, QString &password);
	User(id_t id, QString &username, QString &password, QString &firstAndFamilyName);

	id_t getId() const;
	void setId(id_t id);

	const QString &getUsername() const;
	void setUsername(const QString &username);

	const QString &getPassword() const;
	void setPassword(const QString &password);

	const QString &getFirstAndFamilyName() const;
	void setFirstAndFamilyName(const QString &firstAndFamilyName);

	qint64 getPhoneNumber() const;
	void setPhoneNumber(uint64_t phoneNumber);

	const vector<User *> &getFriends();
	void addFriends(User *user);
};


#endif //ALZACHAT_USER_H
