#ifndef SORT_H
#define SORT_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */
void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, int i);

#endif
