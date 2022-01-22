#ifndef WEATHERAPP_WROCLAW_H
#define WEATHERAPP_WROCLAW_H

#include "../Location.h"
#include "../../Measurement.h"

class Wroclaw : public Location {
public: Measurement sensors = {10.1, 13.2, true};

public:
    Wroclaw(std::string location_name);

    Measurement get_measurement();
};
#endif //WEATHERAPP_WROCLAW_H
