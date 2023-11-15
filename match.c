
#include "monty.h"

/**
 * match - matches the opcode with the corresponding function
 * @head: a pointer to the head of the stack
 * @arg: a string of the tokens of the opcode
 * @line_number: the number of the line in the file
 *
 * Return: 1 in success, -1 in failure
 */

int match(stack_t **head, char **arg, int line_number)
{
	int i;
	instruction_t inst[] ={
	{"push", push},
	{NULL, NULL}
	};

	/* type casting can be made if a function has an additional parameter */
	for (i = 0; i < 1; i++)
	{
		if (strcmp(arg[0], inst[i].opcode))
		{
			inst[i].f(head, line_number);
			return (1);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, arg[0]);
	return (0);
}

/**
 * exiting - safe exit by freeing all the memory allocated in the stack
 * @head; a pointer to the head of the stack
 *
 * Return: Nothing.
 */

void exiting(stack_t *head)
{
	free_stack(head);
	head = NULL;
	exit(EXIT_SUCCESS);
}
