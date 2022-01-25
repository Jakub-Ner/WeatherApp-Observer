#ifndef WEATHERAPP_USERAPP_H
#define WEATHERAPP_USERAPP_H

#include <vector>
#include <string>
#include "../User.h"
#include "../API/CS.h"

class UserApp {
protected:
    std::string string_input;
    CS *m_csi;
    User *m_current_user;
    std::thread csi_thread;
    bool turn_on = true;
public:
    UserApp();

protected:
    void save_measurements();

    void subscribe_location();

    void unsubscribe_location();
    void display_locations() const;
    void display(const std::vector<std::string>& list) const;
    void admin_log();

    void take_string_input();

    void take_short_input(short &short_input);
};


#endif //WEATHERAPP_USERAPP_H
