#ifndef WEATHERAPP_FUNCTIONS_H
#define WEATHERAPP_FUNCTIONS_H

template<typename T>
static int locate_position_by_ptr(std::vector<T *> &list, T *item) {
    return std::find(list.begin(), list.end(), item) - list.begin();
}

template<typename T>
static int locate_position(std::vector<T> &list, T &item) {
    return std::find(list.begin(), list.end(), item) - list.begin();
}

#endif //WEATHERAPP_FUNCTIONS_H
