#include <algorithm>
#include <iostream>
#include "CS.h"
#include "../functions.h"
#include "../locations/locations/Krakow.h"
#include "../locations/locations/Opole.h"
#include "../locations/locations/Siechnice.h"
#include "../locations/locations/Wroclaw.h"
#include "../../Memory_tracker.h"



CS::CS() {
    m_user_list.reserve(3);
    m_user_list.emplace_back(new User("null")); // <- "null" user
    int locations_number = 4;
    m_location_list.reserve(locations_number);

    LOG("Four Locations are allocating");
    m_location_list.emplace_back(new Krakow());
    m_location_list.emplace_back(new Opole());
    m_location_list.emplace_back(new Siechnice());
    m_location_list.emplace_back(new Wroclaw());
    LOG("Locations allocated");

    m_location_list_for_others.reserve(locations_number);
    for (int i = 0; i < m_location_list.size(); i++) {
        m_location_list_for_others.emplace_back(m_location_list[i]->get_location_name());
    }

}

CS::~CS() {
    std::lock_guard<std::mutex> guard(m_synchronize_list);
    for (int i = 0; i < m_location_list.size(); i++) {
        delete m_location_list[i];
    }
    m_location_list.clear();
    m_location_list.shrink_to_fit();

    for (int i = 0; i < m_user_list.size(); i++){
        delete m_user_list[i];
    }
    m_user_list.clear();
    m_user_list.shrink_to_fit();
}


void CS::run() {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::lock_guard<std::mutex> guard(m_synchronize_list);

    for (int i = 0; i < m_location_list.size(); i++) {
        m_location_list[i]->set_measurement();
        for (int j = 0; j < m_location_list[i]->get_user_list_size(); j++) {
            ////  add measurement to list of each user
            m_location_list[i]->get_user(j)\
            .add_measurements(m_location_list[i]->get_measurement());
        }
    }
}

User *const CS::log_in(const std::string &username) {
    for (int i = 0; i < m_user_list.size(); i++) {
        if (m_user_list[i]->get_name() == username) {
            return m_user_list[i];
        }
    }
    return m_user_list[0]; // <- "null" user
}


User *const CS::add_user_and_give_him_location_list(std::string &username) {
    m_user_list.emplace_back(new User(username));
    m_user_list.back()->set_available_locations(m_location_list_for_others);
    return m_user_list.back();
}

bool CS::add_user_to_location(User *user, std::string &wanted_location) {
    int position = locate_position(m_location_list_for_others, wanted_location);
    if (position > m_location_list.size())
        return false;
    std::lock_guard<std::mutex> guard(m_synchronize_list);
    m_location_list[position]->add_user(user);
    return true;
}

bool CS::remove_user_from_location(User *user, std::string &unsub_location) {
    int position = locate_position(m_location_list_for_others, unsub_location);
    if (position > m_location_list.size())
        return false;
    std::lock_guard<std::mutex> guard(m_synchronize_list);
    return m_location_list[position]->remove(user);
}

