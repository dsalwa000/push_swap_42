#include "push_swap.h"

// only for testing, remove after!!!
void display_stack(Node* stack, char ab)
{
  while (stack->prev != NULL)
  {
    printf("value: %d, position: %d\n", stack->value, stack->position);
    stack = stack->prev;
  }
  printf("value: %d, position: %d\n", stack->value, stack->position);
  printf("-\n%c\n\n", ab);
}
