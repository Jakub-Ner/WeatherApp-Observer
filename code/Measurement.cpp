#include "Measurement.h"

#define o std::optional

Measurement::Measurement(std::string location, o<float> &&temperature, o<float> &&humidity, o<bool> &&cloudy)
        : m_location(location), m_temperature(temperature), m_humidity(humidity), m_cloudy(cloudy) {
    srand(time(NULL));
    if (m_humidity) m_mean_humidity = m_humidity.value();
    if (m_temperature) m_mean_temperature = m_temperature.value();
    m_counter = 0;
}

#undef o


void Measurement::set_new_measurements() {
    m_counter++;
    if (m_cloudy) m_cloudy = rand() % 4 <= 1;

    if (m_humidity) {
        m_humidity.value() += (5 - rand() % 10) * m_mean_humidity / 20;
        m_mean_humidity = m_mean_humidity + m_humidity.value() / m_counter;
    }
    if (m_temperature) {
        m_temperature.value() += (5 - rand() % 10) * m_mean_temperature / 20;;
        m_mean_temperature = m_mean_temperature + m_temperature.value() / m_counter;
    }
}

const std::optional<float> &Measurement::get_temperature() const {
    return m_temperature;
}

const std::optional<float> &Measurement::get_humidity() const {
    return m_humidity;
}

const std::optional<bool> &Measurement::get_cloudy() const {
    return m_cloudy;
}

const std::string &Measurement::get_location() const {
    return m_location;
}

