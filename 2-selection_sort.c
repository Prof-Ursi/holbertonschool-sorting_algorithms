#include "sort.h"

/**
 * selection_sort - function sorting an array of integers in ascending order
 * using the Selection sort algorithm.
 *
 * @array: the array to be sorted
 * @size: number of elements in @array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;

	size_t buffer = 0;
	size_t min_index = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			buffer = array[i];
			array[i] = array[min_index];
			array[min_index] = buffer;

			print_array(array, size);
		}
	}
}
