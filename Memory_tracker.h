#ifndef WEATHERAPP_MEMORY_TRACKER_H
#define WEATHERAPP_MEMORY_TRACKER_H

//#define DEBUG

#ifdef DEBUG
#define LOG(x) std::cout<<"--------"<< x << "--------\n"

#include <iostream>

struct Memory_tracker {
    int nr_of_allocations = 0;
    int current_mem_usage = 0;
};

void *operator new(size_t size);

void operator delete(void *memory, size_t size);

#else
#define LOG(x)
#endif DEBUG

#endif //WEATHERAPP_MEMORY_TRACKER_H
