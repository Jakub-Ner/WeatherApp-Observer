#include "Opole.h"


Opole::Opole()
        : Location("Opole") {}

Measurement Opole::get_measurement() {
    sensors.set_new_measurements();
    return sensors;
}


