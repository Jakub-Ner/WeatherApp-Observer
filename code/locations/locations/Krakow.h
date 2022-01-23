#ifndef WEATHERAPP_KRAKOW_H
#define WEATHERAPP_KRAKOW_H

#include "../Location.h"
#include "../../Measurement.h"

class Krakow : public Location {
public: Measurement sensors = {{}, 83.2, true};

public:
    Krakow();
    ~Krakow(){" papa krakow ";}
    Measurement get_measurement();
};
#endif //WEATHERAPP_KRAKOW_H
