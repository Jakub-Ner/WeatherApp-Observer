#ifndef WEATHERAPP_CSI_H
#define WEATHERAPP_CSI_H

#include <algorithm>
#include <iostream>
#include <vector>
#include "../User.h"
#include "../locations/Location.h"


class CSI {
    std::vector<User> m_user_list;
    std::vector<Location *> m_location_list;
    std::vector<std::string> m_location_list_for_others;
public:
    CSI();

    ~CSI();

    User *const log_in(const std::string &username);

    User *const add_user(std::string username);

//    bool find_location(std::string &wanted_location);

    const std::vector<std::string>& get_location_list();

};


#endif //WEATHERAPP_CSI_H
