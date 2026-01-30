/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:28:08 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/28 21:15:43 by dsalwa           ###   ########.fr       */
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
    int   i;

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
    int   length;

    length = 0;
    while (stack != NULL)
    {
        length++;
        stack = stack->prev;
    }
    return (length);
}

int smallest_stack(Node* a)
{
    int value;
    
    value = a->value;
    while (a != NULL)
    {
        if (a->value < value)
            value = a->value;
        a = a->prev;
    }
    return (value);
}

void sort_three(Node** a)
{
    int   first;
    int   second;
    int   third;

    first = (*a)->value;
    second = (*a)->prev->value;
    third = (*a)->prev->prev->value;
    if (first > second && first > third)
        ra(a, 0);
    else if (second > first && second > third)
        rra(a, 0);
    first = (*a)->value;
    second = (*a)->prev->value;
    if (first > second)
        sa(a);
}
