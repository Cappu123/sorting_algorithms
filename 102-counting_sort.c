#include"sort.h"

/**
 * counting_sort - sorts an array od integers using counting sort
 * @array:array of integers.
 * @size: size of array.
*/

void counting_sort(int *array, size_t size)
{
	int *count, *sort, sum, max;
	size_t len;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;

	max = array[0];
	for (len = 1; len < size; len++)
		max = (array[len] > max) ? array[len] : max;
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	for (len = 0; len < (size_t)(max + 1); len++)
		count[len] = 0;

	for (len = 0; len < size; len++)
		count[array[len]]++;

	for (len = 0, sum = 0; len < (size_t)(max + 1); len++)
	{
		count[len] += sum;
		sum = count[len];
	}
	print_array(count, max + 1);

	for (len = 0; len < size; len++)
	{
		sort[count[array[len]] - 1] = array[len];
		count[array[len]]--;
	}
	for (len = 0; len < size; len++)
		array[len] = sort[len];

	free(sort);
	free(count);
}
