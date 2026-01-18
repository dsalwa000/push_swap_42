#include "push_swap.h"

void determine_positions(Node* stack)
{
  int i;

  if (!stack)
    return ;
  i = 0;
  while (stack != NULL)
  {
    stack->position = i;
    stack = stack->prev;
    i++;
  }
}
