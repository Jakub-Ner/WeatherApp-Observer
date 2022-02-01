#include "Location.h"
#include <iostream>
#include <algorithm>
#include "../functions.h"
#include "../../Memory_tracker.h"


Location::Location(std::string &&location_name)
        : m_location_name(location_name) {m_user_list.reserve(5);}

Location::~Location() {
    std::cout << " sensor died ";
}

void Location::add_user(User* const user) {
    m_user_list.emplace_back(user);
}

bool Location::remove(User *user) {
    int position = locate_position_by_ptr(m_user_list, user);
    if (position > m_user_list.size()) return false;
    m_user_list.erase(m_user_list.begin() + position);
    return true;
}

const std::string &Location::get_location_name() {
    return m_location_name;
}

Measurement Location::set_measurement() {
    m_sensors.set_new_measurements();
    return m_sensors;
}

Measurement* const Location::get_measurement() {
    return &m_sensors;
}

User &Location::get_user(int i) {
    return *m_user_list[i];
}

int Location::get_user_list_size() {
    return m_user_list.size();
}
