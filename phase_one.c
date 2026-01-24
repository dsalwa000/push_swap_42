#include "push_swap.h"

int effecient_a_node_position(Node* a, Node *b)
{
  int   final_position;
  int   efficient_cost;
  int   final_cost;

  final_position = 0;
  final_cost = INT_MAX;
  while (a != NULL)
  {
    efficient_cost = costs(combinations(a, b, a->value));
    if (final_cost > efficient_cost)
    {
      final_cost = efficient_cost;
      final_position = a->position;
    }
    a = a->prev;
  }
  return (final_position);
}

void r_movement(Node** a, Node** b, int* smaller, int* bigger)
{
  int i;

  i = 0;
  while (i < smaller[0])
  {
    rr(a, b);
    i++;
  }
  while (i < bigger[0])
  {
    ra(a, 0);
    i++;
  }
}

void move_to_b(Node** a, Node** b, int* a_moves, int* b_moves, int type)
{
  int i;

  i = 0;
  if (type == 0)
    r_movement(a, b, b_moves, a_moves);
  if (type == 1)
    r_movement(a, b, a_moves, b_moves);
  if (type == 2)
    r_movement(a, b, a_moves, b_moves);
  if (type == 3)
    r_movement(a, b, a_moves, b_moves);
}

void use_efficent_position(Node** a, Node** b)
{
  int*  a_moves;
  int*  b_moves;
  int   i;

  while ((*a)->position != effecient_a_node_position(*a, *b))
    *a = (*a)->prev;
  a_moves = a_cost(*a);
  b_moves = b_cost(*b, (*a)->value);
  i = 0;
}
