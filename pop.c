#include "monty.h"

/**
 * pop - removed the top element of the stack
 * @head: a pointer to the head of the list
 * @line_number: the line of the number of the opcode was found
 *
 * Return: Nothing.
 */

void pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (*head)
	{
		tmp = *head;
		if (*head == *gGlobal.tail)
			*gGlobal.tail = NULL;
		*head = tmp->next;
		if (tmp->next)
			tmp->next->prev = NULL;
		free(tmp);
		return;
	}
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	freeAll_and_exit(*head);
}
