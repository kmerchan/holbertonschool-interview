#include "sort.h"

/**
 * merge_sort - sorts an array of ints using top-down merge sort algorithm
 * @array: array of integers to sort
 * @size: size of the array of integers to sort
 *
 */

void merge_sort(int *array, size_t size)
{
	int mid = size / 2;
	int left = 0, right = 0;

	if (size == 0 || array == NULL)
		return;
	if (size <= 2)
	{
		print_array(array);
	}
	merge_sort(array, mid);
	merge_sort(array, size - mid);
}
