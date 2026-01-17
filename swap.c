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

Node* sa(Node* a)
{
  return(swap(a));
}

Node* sb(Node* b)
{
  return(swap(b));
}
