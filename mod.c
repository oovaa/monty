#include "monty.h"

void mod(stack_t **head, unsigned int line_number)
{
	int val;

	if (!(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		freeAll_and_exit(*head);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		freeAll_and_exit(*head);
	}

	val = (*head)->next->n % (*head)->n;

	pop(head, line_number);

	(*head)->n = val;

}
