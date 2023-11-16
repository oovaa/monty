#include "monty.h"
/**
 * push - it adds a new element to the stack
 * @head: a pointer to the head of the list
 * @line_number: the number of the line to be printed if there's an error
 *
 * Return: Nothing.
 */

void push(stack_t **head, unsigned int line_number)
{
	char *val_str = gGlobal.arg[1];
	int i, val;

	if (!val_str)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		freeAll_and_exit(*head);
	}
	for (i = 0; val_str[i]; i++)
	{
		if ((i == 0 && val_str[i] == '-') || val_str[i] == '.')
			continue;
		if (!isdigit(val_str[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			freeAll_and_exit(*head);
		}
	}
	val = atoi(val_str);
	if (gGlobal.isStack)
		add_node(head, val);
	else
		add_node_at_end(head, val);
}

/**
 * add_node - adds a new node
 * @head: a pointer to the head pf the list
 * @val: the data to be inserted into the node
 *
 * Return: Nothing.
 */

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
		*gGlobal.tail = newNode;
	}
	else
	{
		(*head)->prev = newNode;
		newNode->next = *head;
		*head = newNode;
	}
}

/**
 * add_node_at_end - adds a new node at the end of the list
 * @head: a pointer to the head pf the list
 * @val: the data to be inserted into the node
 *
 * Return: Nothing.
 */

void add_node_at_end(stack_t **head, int val)
{
	stack_t *new = malloc(sizeof(stack_t));

	/* creating a new node */
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeAll_and_exit(*head);
	}
	new->n = val;
	new->prev = NULL;
	new->next = NULL;

	/* binding new node with the tail */
	if (*gGlobal.tail)
	{
		(*gGlobal.tail)->next = new;
		new->prev = *gGlobal.tail;
	}
	else
		*head = new;
	*gGlobal.tail = new;
}

/**
 * pall - prints the contents of the stack
 * @head: a pointer to the head pf the list
 * @line_number: the number of the line to be printed if there's an error
 *
 * Return: Nothing.
 */

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
