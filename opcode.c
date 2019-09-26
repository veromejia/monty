#include "monty.h"
/**
 * push - prints the value at the top of the stack
 * @stack: pointer to doble linked list
 * @line_number:given line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	add_dnodeint(stack, line_number);
}

/**
 * pall - prints the value at the top of the stack
 * @stack: pointer to doble linked list
 * @line_number:given line number
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	print_dlistint(*stack);
}


/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to doble linked list
 * @line_number:given line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	dprintf(STDERR_FILENO, "%d\n", (*stack)->n);
}

/**
 * pop - prints the value at the top of the stack
 * @stack: pointer to doble linked list
 * @line_number:given line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = *stack;

	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);

	}

		*stack = new_node->next;
		if (new_node->next != NULL)
			(*stack)->prev = NULL;
		free(new_node);
}
/**
 * swap - prints the value at the top of the stack
 * @stack: pointer to doble linked list
 * @line_number:given line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *next = temp->next;
	int len = dlistint_len(temp);

	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%i: can't swap,stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp->prev = next;
	temp->next = next->next;
	next->prev = NULL;
	*stack = next;
	(*stack)->next = temp;
}