#include <iostream>
#include "KUPA.h"



void KUPA::save_measurements() {
    std::cout << ("Name your file");
//    std::string file_name = take_string_input();
//    KUPA::User::save_measurements(file_name);
}

void KUPA::subscribe_location() {
    std::cout<<"\nWhat location do you want to subscribe?\n";
    take_string_input();
    m_current_user->subscribeLocation(string_input);
}

void KUPA::unsubscribe_location() {

}

void KUPA::take_string_input() {
    std::cin>>string_input;
    while(string_input == "null"){
        std::cout<<"\nInvalid input\n";
        std::cin>>string_input;
    }
}

void KUPA::take_short_input(short& short_input) {
    while (!(std::cin >> short_input)) {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Input have to be int...  Try again: \n";
    }
}

void KUPA::admin_log() {
    std::cout<<"\nusers:\n";

}


//User KUPA::log_in(const std::string& name) const{
//    User::display_locations();
//    for (User user : m_user_list) {
//        if (user.get_name() == name) {
//            return user;
//        }
//    }
//    return NULL;
//}


