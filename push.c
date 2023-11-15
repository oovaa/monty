#include "monty.h"

void push(stack_t **tail, unsigned int line_number) {

	char *val_str = global.av[2];
	int i, val;

	for (i = 0; val_str[i]; i++) {
		if (!isdigit(val_str[i])) {
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(global.stream);
		free(global.av);
		free_stack(*tail);
		exit(EXIT_FAILURE);
		}
	}

	val = atoi(val_str);

	add_node(tail, val);
}

stack_t *tail = NULL;
stack_t *head = NULL;

void add_node(stack_t **head, int val) {
	// Create a new node
	stack_t *newNode = malloc(sizeof(stack_t));
	if (newNode == NULL) {
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	// Set the value of the new node
	newNode->n = val;
	newNode->prev = NULL;
	newNode->next = NULL;

	// If the list is empty, the new node becomes the head
	if (*head == NULL) {
		*head = newNode;
		 tail = newNode;
	} else {
		(*head)->next = newNode;
		newNode->prev = *head;
		*head = newNode;
	}
}



// Function to display the doubly linked list
void printList(stack_t *current) {
    while (current != NULL) {
        printf("%d ", current->n);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Inserting nodes at the end of the list
    add_node(&tail, 1);
    add_node(&tail, 2);
    add_node(&tail, 3);

    // Displaying the doubly linked list
    printf("Doubly Linked List: ");
    printList(tail);

    return 0;
}