/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:10:09 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/30 21:37:43 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min_node(t_node *a)
{
	int		min_value;
	t_node	*min_node;

	min_value = INT_MAX;
	min_node = NULL;
	while (a != NULL)
	{
		if (a->value < min_value)
		{
			min_value = a->value;
			min_node = a;
		}
		a = a->prev;
	}
	return (min_node);
}

int	find_optimal_a(t_node *a, int value_b)
{
	t_node	*current_a;
	t_node	*min_node;
	int		optimal_value;
	int		optimal_position;

	current_a = a;
	optimal_value = INT_MAX;
	optimal_position = 0;
	min_node = find_min_node(a);
	while (current_a)
	{
		if (current_a->value > value_b && current_a->value < optimal_value)
		{
			optimal_value = current_a->value;
			optimal_position = current_a->position;
		}
		current_a = current_a->prev;
	}
	if (optimal_value == INT_MAX)
		return (min_node->position);
	return (optimal_position);
}

void	push_optimal_a(t_node **a, t_node **b)
{
	int		opt_position;
	int		a_length;
	int		i;

	opt_position = find_optimal_a(*a, (*b)->value);
	a_length = stack_length(*a);
	if ((a_length / 2) >= opt_position)
	{
		while (opt_position > 0)
		{
			ra(a, 0);
			opt_position--;
		}
	}
	else
	{
		i = opt_position;
		while (a_length > i)
		{
			rra(a, 0);
			i++;
		}
	}
	pa(a, b);
}

void	push_all_to_a(t_node **a, t_node **b)
{
	t_node	*min_node;
	int		a_length;

	while (*b)
		push_optimal_a(a, b);
	min_node = find_min_node(*a);
	a_length = stack_length(*a);
	if ((a_length / 2) >= min_node->position)
		while (*a != min_node)
			ra(a, 0);
	else
		while (*a != min_node)
			rra(a, 0);
}
