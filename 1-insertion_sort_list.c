#include "sort.h"

/**
 * insertion_sort_list - function sorting a doubly linked list of integers
 * using an insertion sort algorithm
 *
 * @list: double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *previous_node;

	if (!list || !(*list)->next)
		return;

	current_node = (*list)->next;
	while (current_node)
	{
		previous_node = current_node->prev;
		while (previous_node && previous_node->n > current_node->n)
		{
			if (previous_node->prev)
				previous_node->prev->next = current_node;
			else
				*list = current_node;
			current_node->prev = previous_node->prev;
			previous_node->prev = current_node;
			previous_node->next = current_node->next;
			current_node->next = previous_node;
			if (previous_node->next)
				previous_node->next->prev = previous_node;

			print_list(*list);

			previous_node = current_node->prev;
		}
		current_node = current_node->next;
	}
}
