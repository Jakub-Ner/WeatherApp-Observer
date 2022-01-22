#include "Location.h"

Location::Location(const std::string& location_name)
    : m_location_name(location_name) {}

void Location::add_user(const User &user) {
    m_user_list.emplace_back(user);
}

std::string Location::get_location_name() const {
    return m_location_name;
}


