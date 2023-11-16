#include "monty.h"

/**
 * rotr - rotr rotates the stack to the bottom
 * @head: a pointer to the head of the list
 * @line_number: the number of the line to be printed if there's an error
 *
 * Return: Nothing.
 */

void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if ((*head) && *head != *gGlobal.tail)
	{
		tmp = *gGlobal.tail;
		tmp->prev->next = NULL;
		*gGlobal.tail = tmp->prev;
		(*head)->prev = tmp;
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
	}
}
