#include "monty.h"
/**
 * find_func - find the correct function to be execute
 * @opcode: option
 * @value: value
 * @ln: line number
 * Return: 0 on success and -1 on fail
 */
int find_func(char *opcode, char *value, int ln)
{
	int i;
	int flag;

	 instruction_t func_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return (0);
	/*Iterates through list to find the right function*/
	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		/*When 0 found the right opcode*/
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			if (call_fun(func_list[i].f, opcode, value, ln) == -1)
				return (-1);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		dprintf(STDERR_FILENO, "L%i: unknown instruction %s\n", ln, opcode);
		return (-1);
	}
	return (0);
}

/**
* call_fun - Calls the required function.
* @f: Pointer to the function that is about to be called.
* @op: string representing the opcode.
* @val: string representing a numeric value.
* @ln: line numeber for the instruction.
* Return: 0 on success and -1 on fail
*/
int call_fun(op_func f, char *op, char *val, int ln)
{
	stack_t *node;
	int flag;

	flag = 1;

	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL || check_int(val) == -1)
		{
			dprintf(STDERR_FILENO, "L%i: usage: push integer\n", ln);
			return (-1);
		}
		node = create_node(atoi(val) * flag);
		f(&node, ln);
	}
	else
		f(&head, ln);

	return (0);
}
/**
 * create_node - creats a new node
 * @value: value to be add in the node
 * Return: a new doble linked list
 */

stack_t *create_node(int value)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node != NULL)
	{
		node->n = value;
		node->prev = NULL;
		node->next = NULL;
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: malloc fail\n");
		exit(EXIT_FAILURE);
	}
	return (node);

}

/**
 * free_list - frees the allocated memory space
 */
void free_list(void)
{
	stack_t *node;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		node = head;
		head = head->next;
		free(node);
	}
}
