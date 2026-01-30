/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:28:17 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/30 21:36:51 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*swap(t_node *first)
{
	t_node	*second;

	if (first == NULL)
		return (first);
	if (first->prev == NULL)
		return (first);
	second = first->prev;
	first->next = second;
	first->position = 1;
	if (second->prev == NULL)
		first->prev = NULL;
	else
		first->prev = second->prev;
	second->prev = first;
	second->next = NULL;
	second->position = 0;
	first->prev->next = first;
	return (second);
}

void	sa(t_node **a)
{
	if (!a || !*a)
		return ;
	*a = swap(*a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **b)
{
	if (!b || !*b)
		return ;
	*b = swap(*b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **a, t_node **b)
{
	if (!a || !*a || !b || !*b)
		return ;
	sa(a);
	sb(b);
}
