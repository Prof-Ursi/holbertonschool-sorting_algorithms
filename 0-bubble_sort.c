#include "sort.h"
/**
 * swap - échange des éléments
 *
 * @xp: premier élément
 * @yp: élément suivant
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * bubble_sort - trie un tableau d'entiers par ordre croissant en utilisant
 * l'algorithme de tri à bulles
 * @array: tableau à trier
 * @size: taille du tableau
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int check = 1, test;

	if (array == NULL)
	{
		return;
	}

	while (check)
	{
		test = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				print_array(array, size);
				test++;
			}
		}
		if (test == 0)
		{
			check = check * 0;
		}
	}
}

