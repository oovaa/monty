#include "monty.h"

void push(stack_t **head, unsigned int line_number)
{
	char *val_str = global.arg[1];
	int i, val;

	for (i = 0; val_str[i]; i++)
	{
		if (!isdigit(val_str[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			freeAll_and_exit(*head);
		}
	}
	val = atoi(val_str);
	add_node(head, val);
}

void add_node(stack_t **head, int val)
{
	/* Create a new node */
	stack_t *newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeAll_and_exit(*head);
	}
	/* Set the value of the new node */
	newNode->n = val;
	newNode->prev = NULL;
	newNode->next = NULL;

	if (*head == NULL)
	{
		*head = newNode;
		*global.tail = newNode;
	} 
	else
	{
		(*head)->prev = newNode;
		newNode->next = *head;
		*head = newNode;
	}
}

/* Function to display the doubly linked list */
void pall(stack_t **head, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;

	temp = *head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
