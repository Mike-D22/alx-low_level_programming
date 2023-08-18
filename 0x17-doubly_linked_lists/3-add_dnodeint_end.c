#include "lists.h"

/**
 * add_dnodeint_end -it adds a new node at the end
 * of a dlistint_t list
 *
 * @head: head of the list
 * @n: value of the element
 * Return: the address of the new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *z;
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	z = *head;

	if (z != NULL)
	{
		while (z->next != NULL)
			z = z->next;
		z->next = new;
	}
	else
	{
		*head = new;
	}

	new->prev = z;

	return (new);
}
