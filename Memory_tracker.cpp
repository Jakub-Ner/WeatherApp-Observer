#include "Memory_tracker.h"
#ifdef DEBUG

static Memory_tracker memoryTracker;

#define current_mem_usage memoryTracker.current_mem_usage
#define nr_of_allocations memoryTracker.nr_of_allocations

void *operator new(size_t size) {
    current_mem_usage += size;
    nr_of_allocations++;
    std::cout<< nr_of_allocations  << ". Allocated " << size << " in total: " << current_mem_usage << "\n";
    return malloc(size);
}

void operator delete(void *memory, size_t size) {
    free(memory);
    current_mem_usage -= size;
    nr_of_allocations--;
    std::cout << nr_of_allocations << ". Freed " << size << " in total: " << current_mem_usage << "\n";
}
#undef current_mem_usage
#undef nr_of_allocations

#endif