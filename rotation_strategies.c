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

void	rr_ra(t_node **a, t_node **b, int *bigger, int *smaller)
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
		ra(a, 0);
		i++;
	}
}

void	rr_rb(t_node **a, t_node **b, int *bigger, int *smaller)
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
		rb(b, 0);
		i++;
	}
}

void	rrr_rra(t_node **a, t_node **b, int *bigger, int *smaller)
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
		rra(a, 0);
		i++;
	}
}

void	rrr_rrb(t_node **a, t_node **b, int *bigger, int *smaller)
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
		rrb(b, 0);
		i++;
	}
}
