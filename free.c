/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:38:53 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/28 19:37:31 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(Node** stack)
{
    Node*   current;
    Node*   tmp;

    if (!stack || !(*stack))
        return ;
    current = *stack;
    while (current != NULL)
    {
        tmp = current->prev;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}
