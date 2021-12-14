//
// Created by forouzan_a on 11/29/21.
//

#ifndef ALZACHAT_USER_H
#define ALZACHAT_USER_H

#include <string>
#include <vector>

using namespace std;

#define MAX_USERNAME_LEN	80
#define MAX_PASSWORD_LEN	80

class User {
private:
	id_t id;
	string username;
	string password;
	string firstAndFamilyName;
	id_t phoneNumber{};
	vector<User *> friends;
public:
	User(string &username, string &password);
	User(string &username, string &password, string &firstAndFamilyName);

	id_t getId() const;
	void setId(id_t id);

	const string &getUsername() const;
	void setUsername(const string &username);

	const string &getPassword() const;
	void setPassword(const string &password);

	const string &getFirstAndFamilyName() const;
	void setFirstAndFamilyName(const string &firstAndFamilyName);

	uint64_t getPhoneNumber() const;
	void setPhoneNumber(uint64_t phoneNumber);

	const vector<User *> &getFriends();
	void addFriends(User *user);
};


#endif //ALZACHAT_USER_H