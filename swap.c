#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @head: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty file.
 *
 * Description:
 * This function swaps the values of the top two elements on the stack.
 * If the stack contains less than two elements, it prints an error
 * message and exits with EXIT_FAILURE.
 */

void swap(stack_t **head, unsigned int line_number)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		freeAll_and_exit(*head);
	}

	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}
