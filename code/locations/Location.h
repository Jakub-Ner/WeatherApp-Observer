#ifndef WEATHERAPP_LOCATION_H
#define WEATHERAPP_LOCATION_H

#include <vector>
#include "../User.h"

class Location {
    std::string m_location_name;
    std::vector<User> m_user_list;
protected:
    Location(std::string&& location_name);
public:
    ~Location();

public:
    void add_user(const User& user);
    std::string& get_location_name() ;
    virtual Measurement get_measurement() = 0;

    bool remove(User& user);
};

#endif //WEATHERAPP_LOCATION_H
