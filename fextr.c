#include "monty.h"

/**
 * pchar_f - prints the ascii value of the character
 * @stack: double pointer from struct
 * @line_number: the number of every line
 * Return: always
 */

void pchar_f(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_list(*stack);
                exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar(10);
}
