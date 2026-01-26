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

void show_combinations(int* combinations)
{
  printf("c[0]: %d\n", combinations[0]);
  printf("c[1]: %d\n", combinations[1]);
  printf("c[2]: %d\n", combinations[2]);
  printf("c[3]: %d\n", combinations[3]);
}

void show_moves(int* moves, char type)
{
  printf("%c_moves[0]: %d\n", type, moves[0]);
  printf("%c_moves[1]: %d\n", type, moves[1]);
}
