cmake_minimum_required(VERSION 3.21)
project(WeatherApp)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        code/app/Menu.cpp code/app/Menu.h code/app/KUPA.cpp code/app/KUPA.h code/User.cpp code/User.h code/API/CSI.cpp code/API/CSI.h code/locations/Location.cpp code/locations/Location.h shit.cpp shit.h code/Measurement.cpp code/Measurement.h
        code/locations/locations/Siechnice.cpp code/locations/locations/Siechnice.h
        code/locations/locations/Opole.cpp code/locations/locations/Opole.h
        code/locations/locations/Krakow.cpp code/locations/locations/Krakow.h
        code/locations/locations/Wroclaw.cpp code/locations/locations/Wroclaw.h
        code/functions.h)
