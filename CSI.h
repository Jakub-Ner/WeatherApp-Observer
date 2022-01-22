#ifndef WEATHERAPP_CSI_H
#define WEATHERAPP_CSI_H

#include <algorithm>
#include <iostream>
#include <vector>
#include "User.h"
#include "Location.h"


class CSI {
    std::vector<User> m_user_list;
    std::vector<Location> m_location_list;
public:
    CSI();
    User* const log_in(const std::string& username);
    User* const add_user(std::string username);
    bool find_location(std::string& wanted_location);


};


#endif //WEATHERAPP_CSI_H
