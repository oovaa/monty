#include "monty.h"


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
