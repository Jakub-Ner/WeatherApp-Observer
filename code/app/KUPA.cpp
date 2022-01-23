#include <iostream>
#include "KUPA.h"


void KUPA::save_measurements() {
    std::cout << ("Name your file");
//    std::string file_name = take_string_input();
//    KUPA::User::save_measurements(file_name);
}

void KUPA::unsubscribe_location() {
    std::cout << "\nWhat location do you want to unsubscribe?\n\n";
    take_string_input();
    switch (m_current_user->find_location(string_input)) {

        case result_of_subscription::location_not_found:
            std::cout<<"Location not found\n";
            break;
        case result_of_subscription::location_on_user_list:
            if(m_csi->remove_user_from_location(*m_current_user, string_input)) {
                m_current_user->add_location(string_input);
                std::cout << string_input << " has been deleted";
            }
            else std::cout<<"ERROR: Could not find location in CSI";
            break;
        case result_of_subscription::location_available:
            if(m_csi->add_user_to_location(*m_current_user, string_input)){
                m_current_user->add_location(string_input);
                std::cout<<"Location hadn't been subscribed\n";
            }

    }
}

void KUPA::subscribe_location() {
    std::cout << "\nWhat location do you want to subscribe?\n";
    take_string_input();
    switch (m_current_user->find_location(string_input)) {

        case result_of_subscription::location_not_found:
            std::cout<<"\nERROR: Location not found\n";
            break;
        case result_of_subscription::location_on_user_list:
            std::cout<<"\nERROR: Location already added";
            break;
        case result_of_subscription::location_available:
            if(m_csi->add_user_to_location(*m_current_user, string_input)){
                m_current_user->add_location(string_input);
                std::cout<<"\nAdded location :)\n";
            }
            else std::cout<<"\nERROR: Could not found Location in CSI";
            break;

    }
    //    int option = m_current_user->subscribeLocation(string_input);

}

void KUPA::take_string_input() {
    std::cin >> string_input;
    while (string_input == "null") {
        std::cout << "\nInvalid input\n";
        std::cin >> string_input;
    }
}

void KUPA::take_short_input(short &short_input) {
    while (!(std::cin >> short_input)) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Input have to be int...  Try again: \n";
    }
}

void KUPA::admin_log() {
    std::cout << "\nusers:\n";

}

void KUPA::display_locations() const {
    std::cout << "All locations:\n";
    const std::vector<std::string> &all_locations = m_current_user->get_available_locations();
    display(all_locations);

    std::cout << "\n\nYours locations:\n";
    const std::vector<std::string> &user_locations = m_current_user->get_user_locations();
    display(user_locations);
}

void KUPA::display(const std::vector<std::string> &list) const {
    for (int i = 0; i < list.size(); i++)
        std::cout << list[i] << " ";
}

//User KUPA::log_in(const std::string& name) const{
//    User::get_location_list();
//    for (User user : m_user_list) {
//        if (user.get_name() == name) {
//            return user;
//        }
//    }
//    return NULL;
//}


