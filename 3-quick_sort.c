#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 *
 * @array: the array containing the integers
 * @a: index of the first integer to swap.
 * @b: index of the second integer to swap.
 */
void swap(int *array, int a, int b)
{
	int buffer = 0;

	buffer = array[a];
	array[a] = array[b];
	array[b] = buffer;
}

/**
 * partition - Partitions the array using Lomuto partition scheme.
 *
 * @array: the array to be sorted.
 * @low: the low index of the partition.
 * @high: the high index of the partition.
 * @size: the size of the array.
 *
 * Return: the pivot index.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot =  array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(array, i + 1, high);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * recursive_sorting - Recursive function to sort an array using Quick sort.
 *
 * @array: the array to be sorted.
 * @low: the low index of the partition.
 * @high: the high index of the partition.
 * @size: the size of the array.
 */
void recursive_sorting(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		recursive_sorting(array, low, pivot_index - 1, size);
		recursive_sorting(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 *
 * @array: the array to be sorted.
 * @size: number of elements in @array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_sorting(array, 0, size - 1, size);
}
