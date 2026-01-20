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

void ra(Node **a, int rr)
{
  if (!a || !*a)
    return ;
  rotate(a);
  if (!rr)
    ft_putstr_fd("ra\n", 1);
}

void rb(Node **b, int rr)
{
  if (!b || !*b)
    return ;
  rotate(b);
  if (!rr)
    ft_putstr_fd("rb\n", 1);
}

void rr(Node **a, Node **b)
{
  if (!a || !*a || !b || !*b)
    return ;
  ra(a, 1);
  rb(b, 1);
  ft_putstr_fd("rr\n", 1);
}
