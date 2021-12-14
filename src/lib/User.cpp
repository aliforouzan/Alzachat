//
// Created by forouzan_a on 11/29/21.
//

#include "User.h"

#include <utility>
#include "../server/ServerConfig.h"

vector<User> sysUser;

User::User(string &username, string &password) :
	id(sysUser.size()), username(std::move(username)), password(std::move(password)),
	firstAndFamilyName() {}

User::User(string &username, string &password, string &firstAndFamilyName) :
	id(sysUser.size()), username(username), password(password),
	firstAndFamilyName(firstAndFamilyName) {}

id_t User::getId() const {
	return id;
}

void User::setId(id_t id) {
	User::id = id;
}

const string &User::getUsername() const {
	return username;
}

void User::setUsername(const string &username) {
	User::username = username;
}

const string &User::getPassword() const {
	return password;
}

void User::setPassword(const string &password) {
	User::password = password;
}

const string &User::getFirstAndFamilyName() const {
	return firstAndFamilyName;
}

void User::setFirstAndFamilyName(const string &firstAndFamilyName) {
	User::firstAndFamilyName = firstAndFamilyName;
}

uint64_t User::getPhoneNumber() const {
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

