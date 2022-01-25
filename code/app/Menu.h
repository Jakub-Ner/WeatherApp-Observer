#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

#include "UserApp.h"

enum welcome_options {
    create_account = 1, log_in
};
enum main_options {
    display_locations = 1, display_measurements, sub_new_location, unsub_location, log_out, turn_off
};

class Menu : public UserApp {
public:
    void menu();

private:
    void welcome();

    void main_menu();

    void log_in();

    void display_measurement(std::vector<Measurement> measurement_list);
};


#endif //UNTITLED_MENU_H
