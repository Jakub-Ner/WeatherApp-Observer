#include <iostream>
#include "KUPA.h"


void KUPA::save_measurements() {
    std::cout << ("Name your file");
//    std::string file_name = take_string_input();
//    KUPA::User::save_measurements(file_name);
}

void KUPA::subscribe_location() {
    std::cout << "\nWhat location do you want to subscribe?\n";
    take_string_input();
    switch (m_current_user->find_location(string_input)) {

        case result_of_subscription::location_not_found:
            std::cout<<"\nLocation not found\n";
            break;
        case result_of_subscription::location_already_added:
            std::cout<<"\nLocation already added";
            break;
        case result_of_subscription::location_available:
            break;

    }
    //    int option = m_current_user->subscribeLocation(string_input);

}

void KUPA::unsubscribe_location() {

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

    std::cout << "\nYours locations:\n";
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


