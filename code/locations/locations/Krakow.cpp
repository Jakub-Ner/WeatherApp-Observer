#include <iostream>
#include "Krakow.h"


Krakow::Krakow()
        : Location("Krakow") {
    m_sensors = new Measurement(10, 11, {});
}

Krakow::~Krakow() {
    std::cout << " Krakow died \n";
}


