#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @head: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
 *
 * Description:
 * This function prints the value at the top of the stack. If the stack is
 * empty, it prints an error message and exits with EXIT_FAILURE.
 */

void pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		freeAll_and_exit(*head);
	}
	printf("%d\n", (*head)->n);
}
