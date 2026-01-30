/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_strategies.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:10:22 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/30 21:36:51 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_movement(t_node **a, t_node **b, int *bigger, int *smaller, int type)
{
	int	i;

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

void	rr_movement(t_node **a, t_node **b, int *bigger, int *smaller, int type)
{
	int	i;

	i = 0;
	while (i < smaller[1])
	{
		rrr(a, b);
		i++;
	}
	while (i < bigger[1])
	{
		if (type == 0)
			rra(a, 0);
		if (type == 1)
			rrb(b, 0);
		i++;
	}
}

void	type_two_movements(t_node **a, t_node **b, int *a_moves, int *b_moves)
{
	int	i;

	i = 0;
	while (a_moves[0] > i)
	{
		ra(a, 0);
		i++;
	}
	i = 0;
	while (b_moves[1] > i)
	{
		rrb(b, 0);
		i++;
	}
}

void	type_three_movements(t_node **a, t_node **b, int *a_moves, int *b_moves)
{
	int	i;

	i = 0;
	while (a_moves[1] > i)
	{
		rra(a, 0);
		i++;
	}
	i = 0;
	while (b_moves[0] > i)
	{
		rb(b, 0);
		i++;
	}
}
