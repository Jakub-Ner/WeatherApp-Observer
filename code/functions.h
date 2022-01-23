#ifndef WEATHERAPP_FUNCTIONS_H
#define WEATHERAPP_FUNCTIONS_H

template<typename T>
int location_position(std::vector<T> &list, T &item) {
    return std::find(list.begin(), list.end(), item) - list.begin();
}

#endif //WEATHERAPP_FUNCTIONS_H
