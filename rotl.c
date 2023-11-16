#include "monty.h"

/**
 * rotl - Rotates the stack to the bottom.
 * @head: A pointer to the head of the stack.
 * @line_number: The line number in the Monty file.
 */

void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	stack_t *tt = *gGlobal.tail;

	(void) line_number;
	if ((*head) && *head != *gGlobal.tail)
	{
		h = *head;
		*head = (*head)->next;
		h->next->prev = NULL;
		h->next = NULL;

		tt->next = h;
		h->prev = tt;
			
		tt = h;

	}
}
