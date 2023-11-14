#include "monty.h"

// Global variables
stack_t *first = NULL;
stack_t *last = NULL;

// Function to create a new node
stack_t *createNode(int data) {
  stack_t *newNode = (stack_t *)malloc(sizeof(stack_t));
  if (newNode == NULL) {
    fprintf(stderr, "Error: malloc failed\n");
    exit(EXIT_FAILURE);
  }
  newNode->n = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

// Function to insert a node at the end of the list
void add_node(stack_t **head, int data) {
  stack_t *newNode = createNode(data);

  (void)head;

  if (last == NULL) {
    first = newNode;
    last = newNode;
  } else {
    last->next = newNode;
    newNode->prev = last;
    last = newNode;
  }
}

void print(stack_t **first, int ln) {
  if (*first == NULL) {
    fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
    exit(EXIT_FAILURE);
  }

  stack_t *cur = *first;

  while (cur != NULL) {
    printf("%d\n", cur->n);
    cur = cur->next;
  }
}

// Function to display the doubly linked list in reverse
void print_Reverse() {
  stack_t *cur = last;
  while (cur != NULL) {
    printf("%d\n", cur->n);
    cur = cur->prev;
  }
}

void peek() {
  if (last)
    printf("%d\n", last->n);
}

stack_t *pop(unsigned int line_number) {

  if (last == NULL) {
    fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
    exit(EXIT_FAILURE);
  }

  stack_t *tmp = last;

  if (last->prev != NULL) {
    last = last->prev;
    last->next = NULL;
  } else {
    first = NULL;
    last = NULL;
  }

  return tmp;
}

void swap() {
  if (!first || !first->next)
    return;

  stack_t *top = pop(3);
  stack_t *top2 = pop(4);

  if (top != NULL && top2 != NULL) {
    add_node(&last, top->n);
    add_node(&last, top2->n);

    // Free the memory of the popped nodes
    free(top);
    free(top2);
  }
}

void add(stack_t **stack, int line_number) {
  if (*stack == NULL || (*stack)->next == NULL) {
    fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
    exit(EXIT_FAILURE);
  }

  stack_t *top = pop(2);
  last->n += top->n;
  // Free the memory of the popped node
  free(top);
}

void nop() { return; }

int main() {

  int ln = 23;

  // Add nodes to the doubly linked list
  add_node(&last, ln);
  add_node(&last, ln);
  add_node(&last, ln);
  add_node(&last, ln);
  // Display the list before swapping
  printf("Before Swap:\n");
  print(&first, 3);

  // Perform the swap operation
  swap();
  add(&last->prev, ln);

  // Display the list after swapping
  printf("\nAfter Swap:\n");
  print(&first, ln);

  return 0;
}