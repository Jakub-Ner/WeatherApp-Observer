#include "Location.h"

Location::Location(std::string &&location_name)
        : m_location_name(location_name) { std::cout << "siemka"; }

void Location::add_user(const User &user) {
    m_user_list.emplace_back(user);
}

std::string& Location::get_location_name() {
    return m_location_name;
}

Location::~Location() {
    std::cout << "Loc died\n";
}




