#ifndef WEATHERAPP_LOCATION_H
#define WEATHERAPP_LOCATION_H

#include <iostream>
#include <vector>
#include "../User.h"

class Location {
    std::string m_location_name;
    std::vector<User> m_user_list;
protected:
    Location(std::string&& location_name);
public:

public:
    void add_user(const User& user);
    std::string get_location_name() const;
};


#endif //WEATHERAPP_LOCATION_H
