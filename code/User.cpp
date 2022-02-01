#include <iostream>
#include <algorithm>
#include "User.h"
#include "functions.h"
#include "../Memory_tracker.h"

int User::m_dont_care = 0;

User::User(const std::string &name)
        : m_name(name) {
    if (m_dont_care != 0) {
        std::cout << "\n Welcome " << m_name << "!\n";
        m_measurement_list.reserve(10);
    } else m_dont_care = 1;
}

User::User() {

}

User::User(const User &other)
        : m_name(other.m_name) {
    std::cout << "\nCopied " << m_name << "!\n";
}

User::~User() {
    std::cout << "\nBye bye " << m_name << "!";
}


const std::string &User::get_name() const {
    return m_name;
}

void User::add_measurements(Measurement &measurement) {
    m_measurement_list.emplace_back(measurement);
}

std::vector<Measurement> User::get_measurements_list() {
    return m_measurement_list;
}

void User::add_location(std::string &location) {
    m_user_locations.emplace_back(location);
}

const std::vector<std::string> &User::get_available_locations() const {
    return m_available_locations;
}

void User::set_available_locations(const std::vector<std::string> &location_list_for_others) {
    m_available_locations = location_list_for_others;
}

const std::vector<std::string> &User::get_user_locations() const {
    return m_user_locations;
}

int User::find_location(std::string &wanted_location) {
    if (std::any_of(m_user_locations.begin(),
                    m_user_locations.end(),
                    [&](std::string &loc) { return loc == wanted_location; })) {
        return location_on_user_list;
    }

    if (std::any_of(m_available_locations.begin(),
                    m_available_locations.end(),
                    [&](std::string &loc) { return loc == wanted_location; })) {
        return location_available;
    }
    return location_not_found;

}

bool User::remove_location_from_list(std::string location) {
    int position = locate_position(m_user_locations, location);
    if (position > m_user_locations.size()) return false;
    m_user_locations.erase(m_user_locations.begin() + position);
    return true;
}
