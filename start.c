#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

stack_t *tail = NULL;

/*
 * main - Entry point for the program
 * @ac: The number of command-line arguments
 * @av: An array of strings representing the command-line arguments
 *
 * Return: Always 0 (Success)
 */
int main(int ac, char **av)
{
	char *input_str = NULL;
	char **arg = NULL;
	int match = 0, count = 0;
	FILE *stream;
	stack_t *head = NULL;

	stream = openFile(ac, av[1]);
	input_str = readfile(stream);
	while (input_str)
	{
		count++;
		arg = toker(input_str);
		/* comment out later */
		if (arg[0] != NULL)
		{
			match = match(&head, arg, count);
			if (!match)
			{
				free(input_str);
				free(arg);
				free_stack(head);
				head = NULL;
				exit(EXIT_FAILURE);
			}
		}
		free(input_str);
		free(arg);
		input_str = readfile(stream);
	}
	exiting(head);
	return (0);
}
