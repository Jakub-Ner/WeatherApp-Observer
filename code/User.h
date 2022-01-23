#ifndef WEATHERAPP_USER_H
#define WEATHERAPP_USER_H


#include <string>
#include <vector>
#include "Measurement.h"
//#include "locations/Location.h"

enum result_of_subscription{
    location_not_found = 0, location_on_user_list, location_available
};

class User {
protected:
    const std::string m_name;
private:
    static int dont_care;
    std::vector<Measurement> m_measurement_list;
    std::vector<std::string> m_available_locations;
    std::vector<std::string> m_user_locations;

public:
    User(const std::string &name);

    ~User();

    User(const User &other);
public:
    bool operator==(const User& other) const{
        return m_name == other.m_name;
    }
public:
    const std::vector<std::string> & get_user_locations() const;

    void set_available_locations(const std::vector<std::string> &mStringLocationList);

    const std::vector<std::string> & get_available_locations() const;

    const std::string &get_name() const;

    void get_measurements_list() const;

    void add_measurements(const Measurement &measurement) const;

    void add_location(std::string &location);

//    int unsubscribeLocation(const std::string location);
//
//    int subscribeLocation(const std::string location);

    int find_location(std::string &wanted_location);
};


#endif //WEATHERAPP_USER_H
