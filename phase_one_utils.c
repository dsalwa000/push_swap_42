/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_one_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:10:19 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/26 18:10:20 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rb_moves(Node* b, int a_value)
{
  int   min_max[2];
  int   max[2];

  min_max[0] = INT_MIN;
  min_max[1] = b->position;
  max[0] = a_value;
  max[1] = b->position;
  while (b != NULL)
  {
    if (b->value < a_value && b->value > min_max[0])
    {
      min_max[0] = b->value;
      min_max[1] = b->position;
    }
    if (b->value > max[0] && b->value > max[0])
    {
      max[0] = b->value;
      max[1] = b->position;
    }
    b = b->prev;
  }
  if (min_max[0] != INT_MIN)
    return (min_max[1]);
  return (max[1]);
}

int* a_cost(Node* node, int a_length)
{
  int*  a_cost;

  a_cost = (int*)malloc(2 * sizeof(2));
  a_cost[0] = node->position;
  a_cost[1] = a_length - a_cost[0];
  return (a_cost);
}

int* b_cost(Node* b, int a_value)
{
  int*  b_moves;

  b_moves = (int*)malloc(2 * sizeof(int));
  if (!b_moves)
    return NULL;
  b_moves[0] = rb_moves(b, a_value);
  b_moves[1] = stack_length(b) - b_moves[0];
  return (b_moves);
}

int* combinations(Node* node, Node* b, int a_length)
{
  int*  combinations;
  int*  a_moves;
  int*  b_moves;

  combinations = (int*)malloc(4 * sizeof(int));
  a_moves = a_cost(node, a_length);
  b_moves = b_cost(b, node->value);
  if (a_moves[0] > b_moves[0])
    combinations[0] = a_moves[0];
  else
    combinations[0] = b_moves[0];
  if (a_moves[1] > b_moves[1])
    combinations[1] = a_moves[1];
  else
    combinations[1] = b_moves[1];
  combinations[2] = a_moves[0] + b_moves[1];
  combinations[3] = a_moves[1] + b_moves[0];
  return (combinations);
}

int costs(int* combinations, int return_type)
{
  int   costs;
  int   type;
  int   i;

  i = 0;
  type = 0;
  costs = INT_MAX;
  while (4 > i)
  {
    if (combinations[i] < costs)
    {
      costs = combinations[i];
      type = i;
    }
    i++;
  }
  if (return_type)
    return (type);
  return (costs);
}
