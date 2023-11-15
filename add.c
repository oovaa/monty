#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @head: a pointer to the head of the list
 * @line_number: the number of the line to be printed if there's an error
 *
 * Return: Nothing.
 */

void add(stack_t **head, unsigned int line_number)
{
	int value;

	if (*head && *head != *gGlobal.tail)
	{
		value = (*head)->n;
		pop(head, line_number);
		(*head)->n += value;
		return;
	}
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	freeAll_and_exit(*head);
}
