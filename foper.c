#include "monty.h"

/**
 * structs - to generate an array of structs
 * @token1: pointer received to the first token of the line
 * @stack: doble pointer from struct
 * @linecheck: int to know the number of every line
 * Return: none
 */

int structs(char *token1, stack_t **stack, unsigned int linecheck)
{
	int i = 0;
	instruction_t op_func[] = {
		{"push", push_f},
		{"pall", pall_f},
		{"pint", pint_f},
		{"pop", pop_f},
		{"swap", swap_f},
		{NULL, NULL}
		};

	if (token1 == NULL)
		return (0);
	while (op_func[i].opcode != NULL)
	{
		if (strcmp(token1, op_func[i].opcode) == 0)
		{
			op_func[i].f(stack, linecheck);
			return (1);
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", linecheck, token1);
	free_list(*stack);
	exit(EXIT_FAILURE);
}

/**
 * push_f - to push lines contained in a file.
 * @stack: double pointer from struct.
 * @line_number: integer of line number from struct.
 * Return: nothing
 */

void push_f(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	add_node(stack, token2_atoi);
}


/**
 * pall_f - to print the values in the stack
 * @stack: doble pointer from struct
 * @line_number: int to know the number of line from struct
 * Return: nothing
 */

void pall_f(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	(void) line_number;
	if (stack == NULL)
	{
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * pint_f - prints value at the top.
 * @stack: double pointer to list.
 * @line_number: line number.
 * Return: always
 */

void pint_f(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		free_list(*stack);
		printf("L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop_f - removes the top element.
 * @stack: double pointer to list.
 * @line_number: line number.
 * Return: always
 */

void pop_f(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (*stack == NULL)
	{
		free_list(*stack);
		printf("L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	free(h);
}
