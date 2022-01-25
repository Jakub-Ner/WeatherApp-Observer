#include <iostream>
#include "Siechnice.h"


Siechnice::Siechnice()
        : Location("Siechnice") {
    m_sensors = new Measurement(m_location_name, 19, 71, false);
}

Siechnice::~Siechnice() {
    std::cout << " Siechnice died \n";
}
