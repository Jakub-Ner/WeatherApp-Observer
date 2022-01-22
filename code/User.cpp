#include <iostream>
#include "User.h"

User::User(const std::string &name)
        : m_name(name) {
    if (dont_care != 0) {
        std::cout << "\n Welcome " << m_name << "!\n";
    }
    else dont_care = 1;
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

void User::display_locations() const {
    std::cout << "displayam location";

}

bool User::subscribeLocation(const std::string location) {
    return false;
}

void User::add_measurements(const Measurement &measurement) const {

}

void User::save_measurements(const std::string &name) const {

}

bool User::unsubscribeLocation(const std::string location) {
    return false;
}

void User::display_measurements_list() const {

}
