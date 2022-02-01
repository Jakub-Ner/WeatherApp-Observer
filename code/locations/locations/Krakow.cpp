#include <iostream>
#include "Krakow.h"
#include "../../../Memory_tracker.h"


Krakow::Krakow()
        : Location("Krakow") {
    m_sensors = new Measurement(m_location_name, 10, 11, {});
}

Krakow::~Krakow() {
    std::cout << " Krakow died ";
}


