#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers
*                       using the insertion sort algorithm.
* @list: Double pointer to the head of the doubly linked list
*
* Description: Swaps nodes to sort the list in ascending order.
* Prints the list after each swap.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next_node = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			listint_t *prev_node = current->prev;

			/* Adjust previous node's next pointer */
			prev_node->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev_node;

			/* Update current's prev to the node before prev_node */
			current->prev = prev_node->prev;

			/* Adjust the node before prev_node (if it exists) */
			if (prev_node->prev != NULL)
				prev_node->prev->next = current;
			else
				*list = current; /* New head if prev_node was head */

			/* Link current and prev_node */
			current->next = prev_node;
			prev_node->prev = current;

			/* Print the updated list */
			print_list(*list);
		}

		current = next_node;
	}
}
