#include "monty.h"
/**
 * print_dlistint - prints all the elements of a list
 * @h: pointer to doble linked list
 * Return: number of nodes in the list
 */
size_t print_dlistint(const stack_t *h)
{
	size_t i;

	if (h == NULL)
		return (0);
	for (i = 0; h != NULL; i++)
	{
		printf("%d\n", h->n);
		h = h->next;

	}
	return (i);
}

/**
 * dlistint_len - function the show the len of the list
 * @h: pointer to doble linked list
 * Return: the lenght of the list
 */
size_t dlistint_len(const stack_t *h)
{
	size_t i;

	if (h == NULL)
		return (0);
	for (i = 1; h->next != NULL; i++)
		h = h->next;
	return (i);
}

/**
 * add_dnodeint - add a new node at the beggining of the dlist
 * @node: pointer to doble linked list
 * @n: number of line  (unused)
 * Return: always 0
 */
void *add_dnodeint(stack_t **node,  __attribute__((unused))const int n)
{
	stack_t *aux;

	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *node;
		return (0);
	}

	aux = head;
	head = *node;
	head->next = aux;
	aux->prev = head;
	return (0);
}
