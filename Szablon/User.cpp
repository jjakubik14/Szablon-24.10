#include "User.h"
User::User(std::string name):
	name(name) {}
std::string User::getName() {
	return this->name;
}
void User::setName(std::string name) {
	this->name = name;
}
