#include "Krakow.h"


Krakow::Krakow()
        : Location("Krakow") {}

Measurement Krakow::get_measurement() {
    sensors.set_new_measurements();
    return sensors;
}


