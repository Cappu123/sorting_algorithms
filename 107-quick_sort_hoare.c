#include"sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
*/
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subset to order.
 * @last: The last index of the subset to order.
 * Return: final partition index
*/

int hoare_partition(int *array, size_t size, int start, int last)
{
	int pivot, above, below;

	pivot = array[last];
	for (above = start - 1, below = last + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start: The starting index of the array partition to order.
 * @last: The last index of the array partition to order.
*/

void hoare_sort(int *array, size_t size, int start, int last)
{
	int part;

	if (last - start > 0)
	{
		part = hoare_partition(array, size, start, last);
		hoare_sort(array, size, start, part - 1);
		hoare_sort(array, size, part, last);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
