#include "push_swap.h"

Node* swap(Node* first)
{
  Node*   second;
  
  if (first == NULL)
    return first;
  if (first->prev == NULL)
    return first;
  second = first->prev;
  first->next = second;
  first->position = 1;
  if (second->prev == NULL)
    first->prev = NULL;
  else
    first->prev = second->prev;
  second->prev = first;
  second->next = NULL;
  second->position = 0;
  first->prev->next = first;
  return (second);
}

void sa(Node** a)
{
  if (!a || !*a)
    return ;
  *a = swap(*a);
  ft_putstr_fd("sa", 1);
}

void sb(Node** b)
{
  if (!b || !*b)
    return ;
  *b = swap(*b);
  ft_putstr_fd("sb", 1);
}

void ss(Node** a, Node** b)
{
  sa(*a);
  sb(*b);
}
