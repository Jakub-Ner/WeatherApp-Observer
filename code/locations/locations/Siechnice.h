#ifndef WEATHERAPP_SIECHNICE_H
#define WEATHERAPP_SIECHNICE_H

#include "../Location.h"
#include "../../Measurement.h"

class Siechnice : public Location {
public: Measurement sensors = {10.1, {}, true};

public:
    Siechnice();

    Measurement get_measurement();
};
#endif //WEATHERAPP_SIECHNICE_H
