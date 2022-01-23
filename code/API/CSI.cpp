#include "CSI.h"
#include "../locations/locations/Krakow.h"
#include "../locations/locations/Opole.h"
#include "../locations/locations/Siechnice.h"
#include "../locations/locations/Wroclaw.h"

CSI::CSI() {
    m_user_list.reserve(3);
    m_user_list.emplace_back("null");

    m_location_list.reserve(4);
    m_location_list.emplace_back(new Krakow());
    m_location_list.emplace_back(new Opole());
    m_location_list.emplace_back(new Siechnice());
    m_location_list.emplace_back(new Wroclaw());

    for(int i =0; i<m_location_list.size(); i++){
        m_location_list_for_others.emplace_back(m_location_list[i]->get_location_name());
    }
}

User *const CSI::log_in(const std::string &username) {
    for (int i = 0; i < m_user_list.size(); i++) {
        if (m_user_list[i].get_name() == username) {
            return &m_user_list[i];
        }
    }
    return &m_user_list[0];
}

User *const CSI::add_user(std::string username) {
    m_user_list.emplace_back(username);
    m_user_list.back().set_available_locations(m_location_list_for_others);
    return &m_user_list.back();
}

//bool CSI::find_location(std::string &wanted_location) {
//    auto lambda = [&](const Location *location) {
//        return location->get_location_name() == wanted_location;
//    };
//    if (std::any_of(m_location_list.begin(), m_location_list.end(), lambda)) {
//        return true;
//    }
//    return false;
//
//}

const std::vector<std::string>& CSI::get_location_list() {
    return m_location_list_for_others;
}

CSI::~CSI() {
    for (int i = 0; i < m_location_list.size(); i++)
        delete m_location_list[i];
}
