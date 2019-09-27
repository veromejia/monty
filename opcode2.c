#include "monty.h"

/**
 * _mod - module of two elements at the top of the dlinked list
 * @stack: Pointer to a doble linked list
 * @line_number: given line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int len = dlistint_len(temp);

	if (stack == NULL || *stack == NULL || len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_number);
		free(temp);
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		free(temp);
		exit(EXIT_FAILURE);
	}

	temp->next->n %= temp->n;
	pop(stack, line_number);
}
