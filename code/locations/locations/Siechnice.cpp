#include "Siechnice.h"


Siechnice::Siechnice()
        : Location("Siechnice") {}

Measurement Siechnice::get_measurement() {
    sensors.set_new_measurements();
    return sensors;
}


