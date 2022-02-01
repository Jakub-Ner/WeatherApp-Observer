#ifndef WEATHERAPP_LOCATION_H
#define WEATHERAPP_LOCATION_H

#include <vector>
#include <memory>
#include "../User.h"


class Location {
    std::vector<User *> m_user_list;
protected:
    Measurement m_sensors;

    std::string m_location_name;
protected:
    Location(std::string &&location_name);

public:
    virtual ~Location() = 0;

public:
    void add_user(User *user);
    int get_user_list_size();
    std::string &get_location_name();

    User &get_user(int i);

    bool remove(User *user);

    Measurement set_measurement();

    Measurement &get_measurement();
};

#endif //WEATHERAPP_LOCATION_H
