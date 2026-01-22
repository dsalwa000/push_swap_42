#include "push_swap.h"

void init_b(Node** a, Node** b)
{
  pb(a, b);
  pb(a, b);
}

// musimy teraz znalezc max pozycje jezeli nie ma 
// mniejszej liczby od naszego value
int effective_b_node_poistion(Node* b, int value)
{
  int max;
  int position;

  max = b->value;
  position = 0;
  while (b != NULL)
  {
    if (b->value < value && max < value)
    {
      position = b->position;
      max = b->value;
    }
    b = b->prev;
  }
  return (position);
}
