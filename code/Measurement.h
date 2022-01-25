#ifndef WEATHERAPP_MEASUREMENT_H
#define WEATHERAPP_MEASUREMENT_H

#include <optional>

struct Measurement {
private:
    int m_counter;
    std::optional<float> m_temperature;
    std::optional<float> m_humidity;
    std::optional<bool> m_cloudy;
    float m_mean_temperature;
    float m_mean_humidity;

public:
    Measurement(std::optional<float> &&temperature,
                std::optional<float> &&humidity,
                std::optional<bool> &&cloudy);

    void set_new_measurements();

    const std::optional<float> &get_temperature() const;

    const std::optional<float> &get_humidity() const;

    const std::optional<bool> &get_cloudy() const;
};


#endif //WEATHERAPP_MEASUREMENT_H
