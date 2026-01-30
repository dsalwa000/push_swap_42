/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:28:31 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/28 19:38:09 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(Node** from, Node** to)
{
    Node *save;

    if (!from || !to || !*from)
        return ;
    save = (*from);
    if (*to == NULL)
    {
        *to = *from;
        *from = (*from)->prev;
        (*from)->next = NULL;
        (*to)->prev = NULL;
    }
    else
    {
        save = *to;
        (*to)->next = *from;
        *to = (*to)->next;
        (*from) = (*to)->prev;
        (*to)->prev = save;
    }
    determine_positions(*from);
    determine_positions(*to);
}

void pa(Node** a, Node** b)
{
    if (!a || !b || !*b)
        return ;
    push(b, a);  
    ft_putstr_fd("pa\n", 1);
}

void pb(Node** a, Node** b)
{
    if (!a || !b || !*a)
        return ;
    push(a, b);
    ft_putstr_fd("pb\n", 1);
}
