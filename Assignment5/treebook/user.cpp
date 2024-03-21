#include "user.h"
#include <set>
#include <iostream>
#include <string>

User::User() {
    this->name = "";
}

User::User(std::string name) {
// TODO: Implement the additional constructor here!
    this->name = name;
}

User::User(const User & user) {
    this->name = user.getName();
    this->friends = user.getFriends();
}

User& User::operator = (const User & user) {
    if (this == &user) return *this;
    this->name = user.getName();
    this->friends = user.getFriends();
    return *this;
}

User::User(User && user) {
    this->name = std::move(user.getName());
    this->friends = std::move(user.getFriends());
}

User& User::operator = (User && user) {
    if (this != &user)
    {
        this->name = std::move(user.getName());
        this->friends = std::move(user.getFriends());
    }
    return *this;
}

std::string User::getName() const {
    return name;
}

std::set<User> User::getFriends() const {
    return friends;
}

void User::setName(std::string name) {
    this->name = name;
}

// TODO: Implement the < operator overload here!
bool User::operator<(const User &A) const{
    return this->getName() < A.getName();
}

User::~User(){

}