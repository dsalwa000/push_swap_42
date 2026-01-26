/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:10:14 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/26 18:10:15 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int effecient_a_node_position(Node* a, Node *b)
{
  int   final_position;
  int   efficient_cost;
  int   final_cost;
  int   a_length;

  final_position = 0;
  final_cost = INT_MAX;
  a_length = stack_length(a);
  while (a != NULL)
  {
    efficient_cost = costs(combinations(a, b, a_length), 0);
    if (final_cost > efficient_cost)
    {
      final_cost = efficient_cost;
      final_position = a->position;
    }
    a = a->prev;
  }
  return (final_position);
}

void move_to_b(Node** a, Node** b, int* a_moves, int* b_moves, int type)
{
  if (type == 0)
  {
    if (a_moves[0] > b_moves[0])
      r_movement(a, b, a_moves, b_moves, 0);
    else
      r_movement(a, b, b_moves, a_moves, 1);
  }
  else if (type == 1)
  {
    if (a_moves[1] > b_moves[1])
      rr_movement(a, b, a_moves, b_moves, 0);
    else
      rr_movement(a, b, b_moves, a_moves, 1);
  }
  else if (type == 2)
    type_two_movements(a, b, a_moves, b_moves);
  else if (type == 3)
    type_three_movements(a, b, a_moves, b_moves);
}

void use_efficent_position(Node** a, Node** b)
{
  Node* efficient_node;
  int*  a_moves;
  int*  b_moves;
  int   type;
  int   a_length;

  a_length = stack_length(*a);
  efficient_node = *a;
  while (efficient_node->position != effecient_a_node_position(*a, *b))
    efficient_node = efficient_node->prev;
  type = costs(combinations(efficient_node, *b, a_length), 1);
  a_moves = a_cost(efficient_node, a_length);
  b_moves = b_cost(*b, efficient_node->value);
  move_to_b(a, b, a_moves, b_moves, type);
  pb(a, b);
}

void phase_one(Node **a, Node** b)
{
  int length;

  length = stack_length(*a);
  while (length > 3)
  {
    use_efficent_position(a, b);
    length--;
  }
}
