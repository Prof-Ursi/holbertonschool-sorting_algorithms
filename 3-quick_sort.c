Voici le code avec les commentaires traduits en français :

```c
#include "sort.h"

/**
 * quick_sort - trie un tableau d'entiers par ordre croissant (QuickSort)
 * @array: tableau d'entiers
 * @size: nombre d'éléments dans le tableau
 *
 * Description : implémentation de l'algorithme de partitionnement de Lomuto
 * Retourne : N/A
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicker_sort(array, size, 0, size - 1);
}

/**
 * quicker_sort - effectue le véritable tri récursif QuickSort
 * @array: tableau d'entiers
 * @size: nombre d'éléments dans le tableau
 * @l: premier index du tableau
 * @h: dernier index du tableau
 *
 * Retourne : N/A
 */
void quicker_sort(int *array, size_t size, int l, int h)
{
	int i;

	if (l < h)
	{
		i = partition(array, size, l, h);
		quicker_sort(array, size, l, i - 1);
		quicker_sort(array, size, i + 1, h);
	}
}
/**
 * partition - partitionne un tableau d'entiers
 * @array: tableau d'entiers
 * @size: nombre d'éléments du tableau
 * @l: premier index du tableau
 * @h: dernier index du tableau
 *
 * Description : toutes les valeurs doivent être exactes
 * Retourne : nouvelle position d'index
 */
int partition(int *array, size_t size, int l, int h)
{
	int pivot = array[h], i = l, j;

	for (j = l; j <= h - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (pivot != array[i])
	{
		swap(&array[i], &array[h]);
		print_array(array, size);
	}
	return (i);
}

/**
 * swap - échange
 * @a: entier à échanger
 * @b: entier à échanger
 *
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
