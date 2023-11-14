#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * free_stack - frees a stack_t list
 * @head: is the head of the list
 *
 * Return: Nothing.
 */

void free_stack(stack_t *head)
{
	if (head)
	{
		if (head->next)
			free_stack(head->next);
		free(head);
	}
}
