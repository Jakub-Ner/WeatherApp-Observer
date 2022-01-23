#include "Location.h"
#include <iostream>
#include <algorithm>
#include "../functions.h"

Location::Location(std::string &&location_name)
        : m_location_name(location_name) { std::cout << "siemka"; }

void Location::add_user(User* user) {
    m_user_list.emplace_back(user);
}

bool Location::remove(User* user) {
    int position = locate_position_by_ptr(m_user_list, user);
    if(position > m_user_list.size()) return false;
    m_user_list.erase(m_user_list.begin()+position);
    return true;
}

std::string& Location::get_location_name() {
    return m_location_name;
}

Location::~Location() {
    std::cout<<" location died \n";
}
