#include "Wroclaw.h"


Wroclaw::Wroclaw(std::string location_name)
        : Location(location_name) {}

Measurement Wroclaw::get_measurement() {
    sensors.set_new_measurements();
    return sensors;
};
