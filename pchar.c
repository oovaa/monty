#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack, followed by a new line.
 * @head: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the Monty file.
 */


void pchar(stack_t **head, unsigned int line_number)
{

	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		freeAll_and_exit(*head);
	}

	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		freeAll_and_exit(*head);
	}

	printf("%c\n", (*head)->n);

}
