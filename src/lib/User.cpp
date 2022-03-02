/*
 * Alzachat lib User class implementation.
 * Copyright (c) 2021 Alzachat. All rights reserved.
 *                  Ali Forouzan
 */

#include "User.h"
#include "Message.h"

#include <utility>


User::User(id_t id, QString &username, QString &password) :
	id(id), username(std::move(username)), password(std::move(password)),
	firstAndFamilyName() {}

User::User(id_t id, QString &username, QString &password, QString &firstAndFamilyName) :
	id(id), username(username), password(password),
	firstAndFamilyName(firstAndFamilyName) {}

User::User(id_t id) : id(id){}

id_t User::getId() const {
	return id;
}

void User::setId(id_t id) {
	User::id = id;
}

const QString &User::getUsername() const {
	return username;
}

void User::setUsername(const QString &username) {
	User::username = username;
}

const QString &User::getPassword() const {
	return password;
}

void User::setPassword(const QString &password) {
	User::password = password;
}

const QString &User::getFirstAndFamilyName() const {
	return firstAndFamilyName;
}

void User::setFirstAndFamilyName(const QString &firstAndFamilyName) {
	User::firstAndFamilyName = firstAndFamilyName;
}

qint64 User::getPhoneNumber() const {
	return phoneNumber;
}

void User::setPhoneNumber(uint64_t phoneNumber) {
	User::phoneNumber = phoneNumber;
}

const vector<struct User *> & User::getFriends() {
	return friends;
}

void User::addFriends(User *user) {
	User::friends.push_back(user);
}

