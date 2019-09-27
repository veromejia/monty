#include "monty.h"

/**
 * nop - doesn’t do anything.
 * @stack: Pointer to a doble linked list
 * @line_number: given line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * add - adds two elements at the top of the dlinked list
 * @stack: Pointer to a doble linked list
 * @line_number: given line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int len = dlistint_len(temp);

	if (stack == NULL || *stack == NULL || len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		free(temp);
		exit(EXIT_FAILURE);
	}
	temp->next->n += temp->n;
	pop(stack, line_number);
}

/**
 * sub - substracts two elements at the top of the dlinked list
 * @stack: Pointer to a doble linked list
 * @line_number: given line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int len = dlistint_len(temp);

	if (stack == NULL || *stack == NULL || len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_number);
		free(temp);
		exit(EXIT_FAILURE);
	}
	temp->next->n -= temp->n;
	pop(stack, line_number);
}

/**
 * mul - multiplies two elements at the top of the dlinked list
 * @stack: Pointer to a doble linked list
 * @line_number: given line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int len = dlistint_len(temp);

	if (stack == NULL || *stack == NULL || len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		free(temp);
		exit(EXIT_FAILURE);
	}
	temp->next->n *= temp->n;
	pop(stack, line_number);
}

/**
 * _div - divides two elements at the top of the dlinked list
 * @stack: Pointer to a doble linked list
 * @line_number: given line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int len = dlistint_len(temp);

	if (stack == NULL || *stack == NULL || len < 2 || temp->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line_number);
		free(temp);
		exit(EXIT_FAILURE);
	}
	temp->next->n /= temp->n;
	pop(stack, line_number);
}
