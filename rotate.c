#include "push_swap.h"

void rotate(Node** node)
{
  Node* last;
  Node* second;
  Node* first;

  if (!node || !*node)
    return ;
  if ((*node)->prev == NULL)
    return ;
  first = *node;
  second = (*node)->prev;
  last = *node;
  while(last->prev != NULL)
    last = last->prev;
  first->next = last;
  first->prev = NULL;
  second->next = NULL;
  last->prev = first;
  *node = second;
  determine_positions(*node);
}

void ra(Node **a)
{
  if (!a || !*a)
    return ;
  rotate(a);
  ft_putstr_fd("ra\n", 1);
}

void rb(Node **b)
{
  if (!b || !*b)
    return ;
  rotate(b);
  ft_putstr_fd("rb\n", 1);
}

void rr(Node **a, Node **b)
{
  if (!a || !*a || !b || !*b)
    return ;
  ra(a);
  rb(b);
  ft_putstr_fd("rr\n", 1);
}
