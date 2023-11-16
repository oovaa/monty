#include "monty.h"

/**
 * nop - The opcode nop doesn’t do anything.
 * @head: a pointer to the head of the list
 * @line_number: the number of the line to be printed if there's an error
 *
 * Return: Nothing.
 */

void nop(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	(void) head;
}
