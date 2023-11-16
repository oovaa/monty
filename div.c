#include "monty.h"

/**
 * f_div - Divides the second top element of the stack by the top element.
 * @head: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the Monty file.
 */

void f_div(stack_t **head, unsigned int line_number)
{
	int val;

	if (!(*head) || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		freeAll_and_exit(*head);
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		freeAll_and_exit(*head);
	}

	val = (*head)->next->n / (*head)->n;

	pop(head, line_number);

	(*head)->n = val;

}
