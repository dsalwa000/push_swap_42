#include "push_swap.h"

void r_movement(Node** a, Node** b, int* bigger, int* smaller, int type)
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
    if (type == 0)
      ra(a, 0);
    if (type == 1)
      rb(b, 0);
    i++;
  }
}

void rr_movement(Node** a, Node** b, int* bigger, int* smaller, int type)
{
  int i;

  i = 0;
  while (i < smaller[1])
  {
    rrr(a, b);
    i++;
  }
  while (i < bigger[0])
  {
    if (type == 0)
      rra(a, 0);
    if (type == 1)
      rrb(b, 0);
    i++;
  }
}

void mix_movements(Node** a, Node** b, int* a_moves, int* b_moves, int type)
{
  int i;

  i = 0;
  while (a_moves[0] > i)
  {
    if (type == 0)
      ra(a, 0);
    if (type == 1)
      rra(a, 0);
    i++;
  }
  i = 0;
  while (b_moves[1] > i)
  {
    if (type == 0)
      rrb(b, 0);
    if (type == 1)
      rb(b, 0);
    i++;
  }
}

void move_to_b(Node** a, Node** b, int* a_moves, int* b_moves, int type)
{
  if (type == 0)
  {
    if (a_moves[0] > b_moves[0])
      r_movement(a, b, a_moves, b_moves, 0);
    else
      r_movement(a, b, a_moves, a_moves, 1);
  }
  else if (type == 1)
  {
    if (a_moves[1] > b_moves[1])
      rr_movement(a, b, a_moves, b_moves, 0);
    else
      rr_movement(a, b, b_moves, a_moves, 1);
  }
  else if (type == 2)
    mix_movements(a, b, a_moves, b_moves, 0);
  else if (type == 3)
    mix_movements(a, b, a_moves, b_moves, 1);
}

int effecient_a_node_position(Node* a, Node *b)
{
  int   final_position;
  int   efficient_cost;
  int   final_cost;

  final_position = 0;
  final_cost = INT_MAX;
  while (a != NULL)
  {
    efficient_cost = costs(combinations(a, b), 0);
    if (final_cost > efficient_cost)
    {
      final_cost = efficient_cost;
      final_position = a->position;
    }
    a = a->prev;
  }
  return (final_position);
}

void use_efficent_position(Node** a, Node** b)
{
  int*  a_moves;
  int*  b_moves;
  int   type;

  while ((*a)->position != effecient_a_node_position(*a, *b))
    *a = (*a)->prev;
  type = costs(combinations(*a, *b), 1);
  a_moves = a_cost(*a);
  b_moves = b_cost(*b, (*a)->value);
  move_to_b(a, b, a_moves, b_moves, type);
  pb(a, b);
}
