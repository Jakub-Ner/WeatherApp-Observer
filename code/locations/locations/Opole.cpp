#include <iostream>
#include "Opole.h"


Opole::Opole()
        : Location("Opole") {
    m_sensors = new Measurement(10, 11, {});
}

Opole::~Opole() {
    std::cout << " Opole died \n";
}




