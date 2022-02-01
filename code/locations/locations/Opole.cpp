#include <iostream>
#include "Opole.h"
#include "../../../Memory_tracker.h"


Opole::Opole()
        : Location("Opole") {
    m_sensors = Measurement(m_location_name, 10, {}, true);
}

Opole::~Opole() {
    std::cout << " Opole died ";
}




