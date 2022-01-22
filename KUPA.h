#ifndef WEATHERAPP_KUPA_H
#define WEATHERAPP_KUPA_H

#include <vector>
#include <string>
#include "User.h"
#include "CSI.h"

class KUPA {
protected:
    std::string string_input;
    CSI *m_csi = new CSI();
    User *m_current_user;
public:

protected:
    void save_measurements();

    void subscribe_location();

    void unsubscribe_location();

    void admin_log();

    void take_string_input();

    void take_short_input(short &short_input);
};


#endif //WEATHERAPP_KUPA_H
