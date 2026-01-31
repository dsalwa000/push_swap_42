/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:10:14 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/30 22:03:34 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_optimal_b(t_node *a, t_node *b)
{
	int		*current_combinations;
	int		optimal_position;
	int		optimal_cost;
	int		final_cost;
	int		a_length;

	optimal_position = 0;
	final_cost = INT_MAX;
	a_length = stack_length(a);
	while (a != NULL)
	{
		current_combinations = comb(a, b, a_length);
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

void	push_node_to_b(t_node **a, t_node **b, t_node *optimal, int type)
{
	int		*a_moves;
	int		*b_moves;

	a_moves = a_cost(optimal, stack_length(*a));
	b_moves = b_cost(*b, optimal->value);
	if (type == 0)
	{
		if (a_moves[0] > b_moves[0])
			rr_ra(a, b, a_moves, b_moves);
		else
			rr_rb(a, b, b_moves, a_moves);
	}
	else if (type == 1)
	{
		if (a_moves[1] > b_moves[1])
			rrr_rra(a, b, a_moves, b_moves);
		else
			rrr_rrb(a, b, b_moves, a_moves);
	}
	else if (type == 2)
		type_two_movements(a, b, a_moves, b_moves);
	else if (type == 3)
		type_three_movements(a, b, a_moves, b_moves);
	free(a_moves);
	free(b_moves);
}

void	find_and_push_b(t_node **a, t_node **b)
{
	t_node	*optimal;
	int		*combinations;
	int		type;
	int		a_length;

	a_length = stack_length(*a);
	optimal = *a;
	while (optimal->position != find_optimal_b(*a, *b))
		optimal = optimal->prev;
	combinations = comb(optimal, *b, a_length);
	type = costs(combinations, 1);
	free(combinations);
	push_node_to_b(a, b, optimal, type);
	pb(a, b);
}

void	push_all_to_b(t_node **a, t_node **b)
{
	int		length;

	length = stack_length(*a);
	while (length > 3)
	{
		find_and_push_b(a, b);
		length--;
	}
}
