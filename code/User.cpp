#include <iostream>
#include "User.h"

User::User(const std::string &name)
        : m_name(name) {
    if (dont_care != 0) {
        std::cout << "\n Welcome " << m_name << "!\n";
    } else dont_care = 1;
}

User::User(const User &other)
        : m_name(other.m_name) {
    std::cout << "\nCopied " << m_name << "!\n";
}

User::~User() {
    std::cout << "\nBye bye " << m_name << "!\n";
}

int User::dont_care = 0;

const std::string &User::get_name() const {
    return m_name;
}


void User::add_measurements(const Measurement &measurement) const {

}

void User::get_measurements_list() const {

}

void User::add_location(std::string &location) {

}

bool User::subscribeLocation(const std::string location) {
    return false;
}


bool User::unsubscribeLocation(const std::string location) {
    return false;
}

const std::vector<std::string> & User::get_available_locations() const {
    return m_available_locations;
}

void User::set_available_locations(const std::vector<std::string> &mStringLocationList) {
    m_available_locations = mStringLocationList;
}

const std::vector<std::string> & User::get_user_locations() const{
    return m_user_locations;
}
