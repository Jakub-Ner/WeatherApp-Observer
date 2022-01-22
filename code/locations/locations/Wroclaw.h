#ifndef WEATHERAPP_WROCLAW_H
#define WEATHERAPP_WROCLAW_H

#include "../Location.h"
#include "../../Measurement.h"

class Wroclaw : public Location {
public: Measurement sensors = {18.1, 70.2, true};

public:
    Wroclaw();

    Measurement get_measurement();
};
#endif //WEATHERAPP_WROCLAW_H
