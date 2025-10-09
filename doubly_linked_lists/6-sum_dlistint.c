#include "lists.h"

/**
 * sum_dlistint - returns the sum of all data of a dlistint_t list
 * @head: pointer to head of the list
 *
 * Return: sum of elements, or 0 if list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
