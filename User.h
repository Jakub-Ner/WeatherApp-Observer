#ifndef WEATHERAPP_USER_H
#define WEATHERAPP_USER_H


#include <string>
#include <vector>
#include "Measurement.h"

class User {
protected:
    const std::string m_name;
private:
    static int dont_care;
    std::vector<Measurement> measurement_list;

public:
    User(const std::string& name);
    ~User();
    User(const User& other);

    const std::string& get_name()const;

    void display_measurements_list() const;
    void add_measurements(const Measurement& measurement) const;
    void save_measurements(const std::string& name) const;
    void display_locations() const;
    bool unsubscribeLocation(const std::string location);
    bool subscribeLocation(const std::string location);

};


#endif //WEATHERAPP_USER_H
