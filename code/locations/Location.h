#ifndef WEATHERAPP_LOCATION_H
#define WEATHERAPP_LOCATION_H

#include <vector>
#include <memory>
#include "../User.h"


class Location {
    std::string m_location_name;
    std::vector<User*> m_user_list;
protected:
    Location(std::string&& location_name);
    Measurement* m_sensors;
public:
    virtual ~Location();

public:
    void add_user(User* user);
    std::string& get_location_name() ;

    const std::vector<User*>& get_user_list();

    bool remove(User* user);
    Measurement * get_measurement();

};

#endif //WEATHERAPP_LOCATION_H
