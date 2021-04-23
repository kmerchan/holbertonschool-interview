#include "sort.h"

/**
 * heap_sort - sorts an array of ints in ascending order
 * using Heap Sort algorithm
 *
 * @array: the array of ints to sort
 * @size: the size of the array to sort
 *
 */
void heap_sort(int *array, size_t size)
{
	int i = 0, temp = 0;

	if (array == NULL || size <= 1)
		return;
	for (i = (size - 1) / 2; i >= 0; i--)
	{
		heapify(array, size, i);
	}
	for (i = (size - 1); i > 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;

		heapify(array, i, 0);
	}
}

/**
 * heapify - reorders array like nodes swapping in a heap
 *
 * @array: the array of ints to sort
 * @size: the size of the array to sort
 * @i: current index in array
 *
 */
void heapify(int *array, size_t size, int i)
{
	int max = i;
	int left_child = 2 * i + 1;
	int right_child = 2 * i + 2;
	int temp = 0;

	if (left_child < (int)size && array[left_child] > array[max])
		max = left_child;
	if (right_child < (int)size && array[right_child] > array[max])
		max = right_child;
	if (max != i)
	{
		temp = array[i];
		array[i] = array[max];
		array[max] = temp;
		print_array(array, size);

		heapify(array, size, max);
	}
}
