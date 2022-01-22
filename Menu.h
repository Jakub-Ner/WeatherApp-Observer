#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H
#include "iostream"
#include "KUPA.h"
enum welcome_options{
    create_account = 1, log_in
};
enum main_options{
    display_locations = 1, display_measurements, sub_new_location, unsub_location, save_data, log_out
};

class Menu : public KUPA{
private:
public:
    [[noreturn]] void menu();

private:
    void welcome();
    void main_menu();
    void log_in();

};


#endif //UNTITLED_MENU_H
