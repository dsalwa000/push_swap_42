/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 23:56:46 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/12 21:37:11 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(Node *first, Node *second)
{
    Node save;
    
    if (first == NULL || second == NULL)
        return ;
    if (second->prev == NULL)
    {
        first->next = second;
        second->next = NULL;
        first->prev = NULL;
        second->prev = first;
    }
}
