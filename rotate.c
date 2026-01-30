/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:08:51 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/30 21:36:51 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **node)
{
	t_node	*last;
	t_node	*second;
	t_node	*first;

	if (!node || !*node)
		return ;
	if ((*node)->prev == NULL)
		return ;
	first = *node;
	second = (*node)->prev;
	last = *node;
	while (last->prev != NULL)
		last = last->prev;
	first->next = last;
	first->prev = NULL;
	second->next = NULL;
	last->prev = first;
	*node = second;
	determine_positions(*node);
}

void	ra(t_node **a, int rr)
{
	if (!a || !*a)
		return ;
	rotate(a);
	if (!rr)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_node **b, int rr)
{
	if (!b || !*b)
		return ;
	rotate(b);
	if (!rr)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_node **a, t_node **b)
{
	if (!a || !*a || !b || !*b)
		return ;
	ra(a, 1);
	rb(b, 1);
	ft_putstr_fd("rr\n", 1);
}
