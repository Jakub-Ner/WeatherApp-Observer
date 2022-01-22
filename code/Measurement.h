#ifndef WEATHERAPP_MEASUREMENT_H
#define WEATHERAPP_MEASUREMENT_H

#include <optional>

struct Measurement {
private:
    int counter;
public:
    std::optional<float> m_temperature;
    float m_mean_temperature;

    std::optional<float> m_humidity;
    float m_mean_humidity;

    std::optional<bool> m_cloudy;

    Measurement(std::optional<float> temperature,
                std::optional<float> humidity, std::optional<bool> cloudy);

    void set_new_measurements();
    void display_measurement();
};


#endif //WEATHERAPP_MEASUREMENT_H
