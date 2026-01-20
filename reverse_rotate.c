#include "push_swap.h"

void reverse_rotate(Node** node)
{
  Node* first;
  Node* penultimate;
  Node* last;

  if (!node || !*node)
    return ;
  if ((*node)->prev == NULL)
    return ;
  first = *node;
  last = *node;
  while(last->prev != NULL)
    last = last->prev;
  penultimate = last->next;
  last->prev = first;
  last->next = NULL;
  penultimate->prev = NULL;
  first->next = last;
  *node = last;
  determine_positions(*node);
}

void rra(Node **a)
{
  if (!a || !*a)
    return ;
  reverse_rotate(a);
  ft_putstr_fd("rra\n", 1);
}

void rrb(Node **b)
{
  if (!b || !*b)
    return ;
  reverse_rotate(b);
  ft_putstr_fd("rrb\n", 1);
}

void rrr(Node **a, Node **b)
{
  if (!a || !*a || !b || !*b)
    return ;
  rra(a);
  rrb(b);
  ft_putstr_fd("rrr\n", 1);
}
