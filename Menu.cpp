#include "Menu.h"

[[noreturn]] void Menu::menu() {
    welcome();
    while (true){
        main_menu();
    }
}

void Menu::welcome() {

}

void Menu::create_user() {

}

void Menu::log_in() {

}

void Menu::main_menu() {
    std::cout<<R"(
options:\n
[1]-display your list of subscribed locations\n
[2]-display your measurements\n
[3]-subscribe new location\n
[4]-unsubscribe location\n
[5]-save measurements in .json file
[6]-Log out\n)";
}

void Menu::save_measurements() {

}

void Menu::subscribe_location() {

}

void Menu::unsubscribe_location() {

}

std::string Menu::take_string_input() {
    return std::string();
}

int Menu::take_int_input() {
    return 0;
}

void Menu::admin_log() {

}
