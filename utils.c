/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:28:08 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/20 20:28:09 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_b(Node** a, Node** b)
{
  pb(a, b);
  pb(a, b);
}

void determine_positions(Node* stack)
{
  int i;

  if (!stack)
    return ;
  i = 0;
  while (stack != NULL)
  {
    stack->position = i;
    stack = stack->prev;
    i++;
  }
}

int stack_length(Node *stack)
{
  int length;

  length = 0;
  while (stack != NULL)
  {
    length++;
    stack = stack->prev;
  }
  return (length);
}
