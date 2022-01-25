cmake_minimum_required(VERSION 3.21)
project(WeatherApp)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")


include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

add_executable(untitled main.cpp
        code/app/Menu.cpp code/app/Menu.h code/app/UserApp.cpp code/app/UserApp.h code/User.cpp code/User.h code/API/CS.cpp code/API/CS.h code/locations/Location.cpp code/locations/Location.h shit.cpp shit.h code/Measurement.cpp code/Measurement.h
        code/locations/locations/Siechnice.cpp code/locations/locations/Siechnice.h
        code/locations/locations/Opole.cpp code/locations/locations/Opole.h
        code/locations/locations/Krakow.cpp code/locations/locations/Krakow.h
        code/locations/locations/Wroclaw.cpp code/locations/locations/Wroclaw.h
        code/functions.h Tests/main.cpp)

#target_link_libraries(untitled gtest_main)
#add_test(NAME Tests COMMAND untitled)
## Now simply link against gtest or gtest_main as needed. Eg
#add_test(NAME example_test COMMAND example)