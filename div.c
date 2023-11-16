#include "monty.h"

void f_div(stack_t **head, unsigned int line_number)
{
	int val;

	if (!head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		freeAll_and_exit(*head);
	}

	val = (*head)->n;
	if (val == 0)
	{
		fprintf(stderr, "L%d: division by zer\n", line_number);
		freeAll_and_exit(*head);
	}
	
	pop(head, line_number);

	(*head)->n /= val;

}
