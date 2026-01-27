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

int find_optimal_b(Node* a, Node *b)
{
  int*  current_combinations;
  int   optimal_position;
  int   optimal_cost;
  int   final_cost;
  int   a_length;

  optimal_position = 0;
  final_cost = INT_MAX;
  a_length = stack_length(a);
  while (a != NULL)
  {
    current_combinations = combinations(a, b, a_length);
    optimal_cost = costs(current_combinations, 0);
    if (final_cost > optimal_cost)
    {
      final_cost = optimal_cost;
      optimal_position = a->position;
    }
    free(current_combinations);
    a = a->prev;
  }
  return (optimal_position);
}

void push_node_to_b(Node** a, Node** b, int* a_moves, int* b_moves, int type)
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

void find_and_push_b(Node** a, Node** b)
{
  Node* optimal_node;
  int*  our_combinations;
  int*  a_moves;
  int*  b_moves;
  int   type;
  int   a_length;

  a_length = stack_length(*a);
  optimal_node = *a;
  while (optimal_node->position != find_optimal_b(*a, *b))
    optimal_node = optimal_node->prev;
  our_combinations = combinations(optimal_node, *b, a_length);
  type = costs(our_combinations, 1);
  a_moves = a_cost(optimal_node, a_length);
  b_moves = b_cost(*b, optimal_node->value);
  push_node_to_b(a, b, a_moves, b_moves, type);
  free(our_combinations);
  free(a_moves);
  free(b_moves);
  pb(a, b);
}

void push_all_to_b(Node **a, Node** b)
{
  int length;

  length = stack_length(*a);
  while (length > 3)
  {
    find_and_push_b(a, b);
    length--;
  }
}
