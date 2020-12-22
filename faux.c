#include "monty.h"

void atoi_number(char *token2, unsigned int linecheck)
{
	unsigned int i;

	if (token2 != NULL)
	{
		for (i = 0; token2[i] != 0; i++)
			if ((token2[i] < 48 && token2[i] != 45) || token2[i] > 57)
			{
				fprintf(stderr, "L%d: usage: push integer", linecheck);
				exit(EXIT_FAILURE);
			}
			else
			{
				token2_atoi = atoi(token2);
				return;
			}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer", linecheck);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_list - function that frees a list.
 * @head: double pointer list.
 * Return: always.
 */

void free_list(stack_t *head)
{
	stack_t *aux = NULL;

	while (head != NULL)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
	free(head);
}


/**
 * add_node - to add node at the beginning
 * @stack: doble pointer from struct
 * @line_number: int to know the number of line from struct
 * Return: int.
 */

void *add_node(stack_t **stack, unsigned int number)
{
	stack_t *new = NULL;

	if (stack == NULL)
	{
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
    	new->n = number;
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
	return (new);
}
