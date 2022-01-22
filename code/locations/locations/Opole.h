#ifndef WEATHERAPP_OPOLE_H
#define WEATHERAPP_OPOLE_H

#include "../Location.h"
#include "../../Measurement.h"

class Opole : public Location {
public: Measurement sensors = {21.1, 13.2, {}};

public:
    Opole();

    Measurement get_measurement();
};
#endif //WEATHERAPP_OPOLE_H
