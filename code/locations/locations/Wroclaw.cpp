#include <iostream>
#include "Wroclaw.h"


Wroclaw::Wroclaw()
        : Location("Wroclaw") {
    m_sensors = new Measurement(m_location_name, 19, 71, false);
}

Wroclaw::~Wroclaw() {
    std::cout << " Wroclaw died \n";
}

