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

	if (size <= 1 || array == NULL)
		return;
	merge_sort(array, mid);
	merge_sort(&array[mid], size - mid);
	merge(array, mid, size);
}


/**
 * merge - merges two subarrays together
 * @array: array to merge
 * @mid: index of mid-point
 * @size: size of array to merge
 *
 */

void merge(int *array, int mid, size_t size)
{
	int *holder = malloc(sizeof(int) * size);
	int left = 0, right = mid, index = 0;

	if (holder == NULL)
		return;
	printf("Merging...\n[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(&array[mid], size - mid);
	while (left < mid && right < (int)size)
	{
		if (array[left] <= array[right])
		{
			holder[index] = array[left];
			left++;
		}
		else
		{
			holder[index] = array[right];
			right++;
		}
		index++;
	}
	while (left < mid)
	{
		holder[index] = array[left];
		left++;
		index++;
	}
	while (right < (int)size)
	{
		holder[index] = array[right];
		right++;
		index++;
	}
	for (index = 0; index < (int)size; index++)
		array[index] = holder[index];
	printf("[Done]: ");
	print_array(array, size);
}
