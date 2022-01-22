#include "CSI.h"

CSI::CSI() {
    m_user_list.reserve(3);
    m_user_list.emplace_back("null");
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
    return &m_user_list.back();
}

bool CSI::find_location(std::string &wanted_location) {
    auto lambda = [&](const Location &location) {
        return location.get_location_name() == wanted_location;};
    if(std::any_of(m_location_list.begin(), m_location_list.end(), lambda)){
        return true;
    }
    return false;

}
