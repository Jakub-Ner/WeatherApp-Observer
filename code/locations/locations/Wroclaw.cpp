#include "Wroclaw.h"


Wroclaw::Wroclaw()
        : Location("Wroclaw") {
    m_sensors = new Measurement(19, 71, false);
}


