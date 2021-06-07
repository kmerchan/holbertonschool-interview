#ifndef SORT_H
#define SORT_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>

/* FUNCTION PROTOTYPES */
/* Given function to print array */
void print_array(const int *array, size_t size);
/* Function to implement top-down merge sort algorithm */
void merge_sort(int *array, size_t size);
void merge(int *array, int mid, size_t size);

#endif
