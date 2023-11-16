#include "monty.h"

/**
 * rotl - Rotates the stack to the bottom.
 * @head: A pointer to the head of the stack.
 * @line_number: The line number in the Monty file.
 */

void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if ((*head) && (*head)->next)
	{
		tmp = *head;
		*head = tmp->next;
		tmp->next->prev = NULL;
		(*gGlobal.tail)->next = tmp;
		tmp->next = NULL;
		tmp->prev = *gGlobal.tail;
		*gGlobal.tail = tmp;
	}
}
