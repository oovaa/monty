#include "monty.h"

/**
 * sub -  subtracts the top element from the second top of the stack
 * @head: a pointer to the head of the list
 * @line_number: the number of the line to be printed if there's an error
 *
 * Return: Nothing.
 */

void sub(stack_t **head, unsigned int line_number)
{
	if (!(*head) ||  *head == *gGlobal.tail)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		freeAll_and_exit(*head);
	}
	(*head)->next->n -= (*head)->n;
	pop(head, line_number);
}
