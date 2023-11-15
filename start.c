#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

global_t global = {NULL, NULL, NULL, NULL, 0};

/*
 * main - Entry point for the program
 * @ac: The number of command-line arguments
 * @av: An array of strings representing the command-line arguments
 *
 * Return: Always 0 (Success)
 */

int main(int ac, char **av) {
	char *input_str = NULL, **arg = NULL;
	int isMatch = 0, line_number = 0;
	FILE *stream;
	stack_t *head = NULL;
	stack_t *tail = NULL;

	stream = openFile(ac, av[1]);
	input_str = readfile(stream);
	/* the structure packing */
	global.stream = stream;
	global.str = input_str;
	global.tail = &tail;
	global.isStack = 1;

	while (input_str)
	{
		line_number++;
		arg = toker(input_str, stream);
		global.arg = arg;
		if (arg[0] != NULL)
		{
			isMatch = match(&head, arg, line_number);
			if (!isMatch)
				freeAll_and_exit(head);
		}
		free(input_str);
		free(arg);
		input_str = readfile(stream);
		global.str = input_str;
	}
	fclose(stream);
	exiting(head);
	return (0);
}
