#include "monty.h"
#define TOKEN_DELIMITER " \t\n\r"
int token2_atoi;

/**
 * main - tokenize and executing all functions
 * @argc: counter of arguments
 * @argv: arguments received from the prompt
 * Return: nothing
 */

int main(int argc, char *argv[])
{
	FILE *stream;
	size_t len;
	ssize_t read;
	char *token1, *token2, *line;
	stack_t *head = NULL;
	unsigned int linecheck = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, stream)) != -1)
	{
		while (line[0] == 32)
			line++;
		if (line[0] == '\n' || line[0] == '\0')
			continue;
		token1 = strtok(line, TOKEN_DELIMITER);
		token2 = strtok(NULL, TOKEN_DELIMITER);
		/* once token2 exists convert it to int */
		if (strcmp(token1, "push") == 0)
			atoi_number(token2, linecheck);
		structs(token1, &head, linecheck);
		linecheck++;
	}
	free(line);
	free_list(head);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
