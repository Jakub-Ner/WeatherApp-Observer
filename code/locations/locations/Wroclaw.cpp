#include <iostream>
#include "Wroclaw.h"
#include "../../../Memory_tracker.h"


Wroclaw::Wroclaw()
        : Location("Wroclaw") {
    m_sensors = Measurement(m_location_name, 19, 71, false);
}

Wroclaw::~Wroclaw() {
    std::cout << " Wroclaw died ";
}

