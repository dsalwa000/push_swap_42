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

void rra(Node **a, int rrr)
{
  if (!a || !*a)
    return ;
  reverse_rotate(a);
  if (!rrr)
    ft_putstr_fd("rra\n", 1);
}

void rrb(Node **b, int rrr)
{
  if (!b || !*b)
    return ;
  reverse_rotate(b);
  if (!rrr)
    ft_putstr_fd("rrb\n", 1);
}

void rrr(Node **a, Node **b)
{
  if (!a || !*a || !b || !*b)
    return ;
  rra(a, 1);
  rrb(b, 1);
  ft_putstr_fd("rrr\n", 1);
}
