#include "Wroclaw.h"


Wroclaw::Wroclaw()
        : Location("Wroclaw") {}

Measurement Wroclaw::get_measurement() {
    sensors.set_new_measurements();
    return sensors;
}


