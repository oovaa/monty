#include "monty.h"

/**
 * pstr_t - prints the string followed by a new line
 * @head: the head of the list
 *
 * Return: Nothing.
 */

void pstr_t(stack_t *head)
{
	if (head && (head->n > 0 && head->n < 128))
	{
		putchar(head->n);
		pstr_t(head->next);
	}
	else
		putchar('\n');
}

/**
 * pstr - a helper function for pstr_t
 * @head: a pointer to the head of the list
 * @line_number: the number of the line to be printed if there's an error
 *
 * Return: Nothing.
 */

void pstr(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	pstr_t(*head);
}
