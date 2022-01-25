#include <algorithm>
#include "CS.h"
#include "../functions.h"
#include "../locations/locations/Krakow.h"
#include "../locations/locations/Opole.h"
#include "../locations/locations/Siechnice.h"
#include "../locations/locations/Wroclaw.h"

CS::CS() {
    m_user_list.reserve(3);
    m_user_list.emplace_back(new User("null"));

    int locations_number = 4;
    m_location_list.reserve(locations_number);
    m_location_list.emplace_back(new Krakow());
    m_location_list.emplace_back(new Opole());
    m_location_list.emplace_back(new Siechnice());
    m_location_list.emplace_back(new Wroclaw());

    m_location_list_for_others.reserve(locations_number);
    for (int i = 0; i < m_location_list.size(); i++) {
        m_location_list_for_others.emplace_back(m_location_list[i]->get_location_name());
    }

}

void CS::run() {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::lock_guard<std::mutex> guard(synchronize_list);

    for (int i = 0; i < m_location_list.size(); i++) {
        for (int j = 0; j < m_location_list[i]->get_user_list().size(); j++) {
            m_location_list[i]->get_user_list()[j]\
            ->add_measurements(m_location_list[i]->get_measurement());
        }
    }
}


User *const CS::log_in(const std::string &username) {
    for (int i = 0; i < m_user_list.size(); i++) {
        if (m_user_list[i]->get_name() == username) {
            return m_user_list[i];
        }
    }
    return m_user_list[0];
}

User *const CS::add_user(std::string username) {
    m_user_list.emplace_back(new User(username));
    m_user_list.back()->set_available_locations(m_location_list_for_others);
    return m_user_list.back();
}

const std::vector<std::string> &CS::get_location_list() {
    return m_location_list_for_others;
}

CS::~CS() {
    std::lock_guard<std::mutex> guard(synchronize_list);
    for (int i = 0; i < m_location_list.size(); i++)
        delete m_location_list[i];
}

bool CS::add_user_to_location(User *user, std::string &wanted_location) {
    int position = locate_position(m_location_list_for_others, wanted_location);
    if (position > m_location_list.size())
        return false;
    std::lock_guard<std::mutex> guard(synchronize_list);
    m_location_list[position]->add_user(user);
    return true;
}

bool CS::remove_user_from_location(User *user, std::string unsub_location) {
    int position = locate_position(m_location_list_for_others, unsub_location);
    if (position > m_location_list.size())
        return false;
    std::lock_guard<std::mutex> guard(synchronize_list);
    return m_location_list[position]->remove(user);
}

