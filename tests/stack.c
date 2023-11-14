#include "monty.h"

// Global variables
stack_t *first = NULL;
stack_t *last = NULL;

// Function to create a new node
stack_t *createNode(int data) {
  stack_t *newNode = (stack_t *)malloc(sizeof(stack_t));
  newNode->n = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

// Function to insert a node at the end of the list
void add_node(int data) {
  stack_t *newNode = createNode(data);

  if (last == NULL) {
    first = newNode;
    last = newNode;
  } else {
    last->next = newNode;
    newNode->prev = last;
    last = newNode;
  }
}

// Function to display the doubly linked list
void print() {
  stack_t *cur = first;
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

stack_t *pop() {
  if (last == NULL)
    return NULL;

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

  stack_t *top = pop();
  stack_t *top2 = pop();

  if (top != NULL && top2 != NULL) {
    add_node(top->n);
    add_node(top2->n);

    // Free the memory of the popped nodes
    free(top);
    free(top2);
  }
}

void add() {
  if (!last)
    return;

  stack_t *top = pop();

  if (top != NULL)
    last->n += top->n;

  free(top);
}

void nop() { return; }

int main() {

  // Add nodes to the doubly linked list
  add_node(1);
  add_node(2);
  add_node(3);

  // Display the list before swapping
  printf("Before Swap:\n");
  print();

  // Perform the swap operation
  swap();
  add();

  // Display the list after swapping
  printf("\nAfter Swap:\n");
  print();

  return 0;
}