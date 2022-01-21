#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H
#include "iostream"
enum options{
    display_locations = 1, display_measurements, sub_new_location, unsub_location, save_data, log_out
};

class Menu {
public:
    [[noreturn]] void menu();

private:
void welcome();
void create_user();
void log_in();
void main_menu();
void save_measurements();
void subscribe_location();
void unsubscribe_location();
std::string take_string_input();
int take_int_input();
void admin_log();

};


#endif //UNTITLED_MENU_H
