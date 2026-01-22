#include "push_swap.h"

// only for testing, remove after!!!
void display_stack(Node* stack, char ab)
{
  while (stack != NULL)
  {
    printf("value: %d, position: %d\n", stack->value, stack->position);
    stack = stack->prev;
  }
  printf("-\n%c\n\n", ab);
}

void display_stacks(Node *a, Node *b)
{
  display_stack(a, 'a');
  display_stack(b, 'b');
  printf("__________\n\n");
}