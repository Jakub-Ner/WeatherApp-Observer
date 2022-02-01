#include <iostream>
#include "Opole.h"
#include "../../../Memory_tracker.h"


Opole::Opole()
        : Location("Opole") {
    m_sensors = new Measurement(m_location_name, 10, 11, {});
}

Opole::~Opole() {
    std::cout << " Opole died ";
}




