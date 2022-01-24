#include <iostream>
#include <iomanip>
#include "Measurement.h"

using std::optional;

Measurement::Measurement(optional<float>&& temperature, optional<float>&& humidity, optional<bool>&& cloudy)
        : m_temperature(temperature), m_humidity(humidity), m_cloudy(cloudy) {
    srand(time(NULL));
    if (m_humidity) m_mean_humidity = m_humidity.value();
    if (m_temperature) m_mean_temperature = m_temperature.value();
    counter = 0;
}

void Measurement::set_new_measurements() {
    counter++;
    if (m_cloudy) m_cloudy = rand() % 4 <= 1;

    if (m_humidity) {
        m_humidity.value() += (5 - rand() % 10) * m_mean_humidity / 20;
        m_mean_humidity = m_mean_humidity + m_humidity.value() / counter;
    }
    if (m_temperature) {
        m_temperature.value() += (5 - rand() % 10) * m_mean_temperature / 20;;
        m_mean_temperature = m_mean_temperature + m_temperature.value() / counter;
    }
}

