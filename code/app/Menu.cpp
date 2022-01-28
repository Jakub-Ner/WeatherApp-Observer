#include <iostream>
#include <iomanip>

#include "Menu.h"
#include "UserApp.h"

void Menu::menu() {
    welcome();
    while (m_turn_on) {
        main_menu();
    }
    m_csi_thread.join();
}

void Menu::welcome() {
    std::cout << R"(
Hi!
[1]-create an account
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
                m_current_user = m_cs->add_user_and_give_him_location_list(m_string_input);
            } else {
                std::cout << "\nThis username is already in use. Try be more creative :)\n";
                welcome();
            }
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
    m_current_user = m_cs->log_in(m_string_input);
}


void Menu::main_menu() {
    std::cout << R"(

available options:
[1]-display locations
[2]-display your measurements
[3]-subscribe new location
[4]-unsubscribe location
[5]-Log out
[6]-turn off
)";
    short short_input;
    UserApp::take_short_input(short_input);
    while (short_input < 1 || short_input > main_options::turn_off) {
        std::cout << "Input int value out of: 1,2,3,4,5,6\n";
        UserApp::take_short_input(short_input);
    }
    switch (short_input) {
        case main_options::display_locations:
            UserApp::display_locations();
            break;

        case main_options::display_measurements:
            display_measurement(m_current_user->get_measurements_list());
            break;

        case main_options::sub_new_location:
            UserApp::subscribe_location();
            break;

        case main_options::unsub_location:
            UserApp::unsubscribe_location();
            break;

        case main_options::log_out:
            menu();

        case main_options::turn_off:
            m_turn_on = false;
            break;
    }
}

void Menu::display_measurement(std::vector<Measurement> measurement_list) {
    std::cout << std::setprecision(2) << std::fixed;
    for (int i = 0; i < measurement_list.size(); i++) {
        std::cout << "\"location\":" << measurement_list[i].get_location() << ",";
        try {
            std::cout << "\"m_temperature\":" << measurement_list[i].get_temperature().value() << ",";
        } catch (const std::bad_optional_access &e) {
            std::cout << "\"" << e.what() << "\",";
        }

        try {
            std::cout << "\"m_humidity\":" << measurement_list[i].get_humidity().value() << ",";
        } catch (const std::bad_optional_access &e) {
            std::cout << "\"" << e.what() << "\",";
        }

        try {
            std::cout << "\"m_cloudy\":" << measurement_list[i].get_cloudy().value();
        } catch (const std::bad_optional_access &e) {
            std::cout << "\"" << e.what() << "\"";
        }
        std::cout << "\n";
    }
}


