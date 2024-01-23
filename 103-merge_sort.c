#include "sort.h"

/**
 * merge_sub - merge sorting algorithm function.
 * @subarray: array split into sub array.
 * @buffer: buffer of array.
 * @low: low partition.
 * @mid: mid partition.
 * @high: high partition.
*/

void merge_sub(int *subarray, int *buffer, size_t low, size_t mid, size_t high)
{
	size_t lower;
	size_t middle;
	size_t a = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + low, mid - low);

	printf("[right]: ");
	print_array(subarray + mid, high - mid);

	for (lower = low, middle = mid; lower < mid && middle < high; a++)
	{
		buffer[a] = (subarray[lower] < subarray[middle])
			? subarray[lower++] : subarray[middle++];
	}
	for (; lower < middle; lower++)
	{
		buffer[a++] = subarray[lower];
	}
	for (; middle < high; middle++)
	{
		buffer[a++] = subarray[middle];
	}
	for (lower = low, a = 0; lower < high; lower++)
	{
		subarray[lower] = buffer[a++];
	}
	printf("[Done]: ");
	print_array(subarray + low, high - low);
}

/**
 * merge_sort_call - sorts an array of integers using merge sort.
 * @subarray: subarray to be sorted.
 * @buffer: buffer of array.
 * @low: low partition.
 * @high: high partition.
*/

void merge_sort_call(int *subarray, int *buffer, size_t low, size_t high)
{
	size_t mid;

	if (high - low > 1)
	{
		mid = low + (high - low) / 2;
		merge_sort_call(subarray, buffer, low, mid);
		merge_sort_call(subarray, buffer, mid, high);
		merge_sub(subarray, buffer, low, mid, high);
	}
}

/**
 * merge_sort - merge sort algorithm implementation
 * @array: array to be sorted.
 * @size: size of array to be sorted.
*/

void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_call(array, buffer, 0, size);

	free(buffer);
}
