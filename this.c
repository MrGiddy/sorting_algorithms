#include "sort.h"

/**
 * insertion_sort - Sorts a doubly linked list in ascending order
 * @list: The doubly linked list to sort
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp, *sorted;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = *list;
	while (curr != NULL)
	{
		temp = curr->next;
		/* Detach curr from list */
		if (curr == *list)
		{
			*list = curr->next;  /* Special handling for first node */
		}
		else
		{
			curr->prev->next = curr->next;
		}
		if (curr->next != NULL)
			curr->next->prev = curr->prev;

		/* Find correct position to re-insert curr */
		sorted = *list;
		while (sorted->next != NULL && sorted->next->n < curr->n)
		{
			sorted = sorted->next;
		}
		/* Insert curr back into the list */
		curr->next = sorted->next;
		curr->prev = sorted;
		if (sorted->next != NULL)
			sorted->next->prev = curr;
		sorted->next = curr;

		curr = temp;
	}
	/* Update *list to point to the head of the sorted list */
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}
