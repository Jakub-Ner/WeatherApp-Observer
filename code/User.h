#ifndef WEATHERAPP_USER_H
#define WEATHERAPP_USER_H


#include <string>
#include <vector>
#include "Measurement.h"
//#include "locations/Location.h"

class User {
protected:
    const std::string m_name;
private:
    static int dont_care;
    std::vector<Measurement> m_measurement_list;
//    std::vector<Location> m_location_list;
    std::vector<std::string*> m_string_location_list;
public:
    const std::vector<std::string *> getMStringLocationList() const;

public:
    User(const std::string& name);
    ~User();
    User(const User& other);

    const std::string& get_name()const;

    void get_measurements_list() const;
    void add_measurements(const Measurement& measurement) const;

    void add_location(std::string& location);

    bool unsubscribeLocation(const std::string location);
    bool subscribeLocation(const std::string location);

};


#endif //WEATHERAPP_USER_H
