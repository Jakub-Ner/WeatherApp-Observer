#include <iostream>

#include "Menu.h"
#include "KUPA.h"

void Menu::menu() {
    welcome();
    while (true) {
        main_menu();
    }
}

void Menu::welcome() {
    std::cout << R"(
Hi!
[1]-create an acount
[2]-log-in
)";
    short short_input;
    take_short_input(short_input);
    while (short_input < 1 || short_input > welcome_options::log_in) {
        std::cout << "Input int value out of: 1,2,3,4,5,6\n";
        take_short_input(short_input);
    }
    switch (short_input) {

        case welcome_options::create_account:
            std::cout << "\nSet your username\n";
            log_in();
            if ((*m_current_user).get_name() == "null") {
                m_current_user = m_csi->add_user(string_input);
            } else welcome();
            break;

        case welcome_options::log_in:
            std::cout << "\nEnter your username\n";
            log_in();
            if ((*m_current_user).get_name() == "null") {
                std::cout << "\nCouldn't find the user\n";
                welcome();
            }
            break;
    }
}

void Menu::log_in() {
    take_string_input();
    m_current_user = m_csi->log_in(string_input);
}


void Menu::main_menu() {
    std::cout << R"(

main_options:
[1]-display locations
[2]-display your measurements
[3]-subscribe new location
[4]-unsubscribe location
[5]-save measurements in .json file
[6]-Log out
)";
    short short_input;
    KUPA::take_short_input(short_input);
    while (short_input < 1 || short_input > main_options::log_out) {
        std::cout << "Input int value out of: 1,2,3,4,5,6\n";
        KUPA::take_short_input(short_input);
    }
    switch (short_input) {
        case main_options::display_locations:
            KUPA::display_locations();
            break;

        case main_options::display_measurements:
            KUPA::m_current_user->get_measurements_list();
            break;

        case main_options::sub_new_location:
            KUPA::subscribe_location();
            break;

        case main_options::unsub_location:
            KUPA::unsubscribe_location();
            break;

        case main_options::save_data:
            KUPA::save_measurements();
            break;

        case main_options::log_out:
            menu();
    }
}




