/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:10:09 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/26 21:08:00 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_optimal_a(Node* a, int value)
{
    int     optimal_value;
    int     optimal_position;
    
    optimal_value = INT_MIN;
    optimal_position = 0;
    while (a != NULL)
    {
        if (value > a->value && a->value < optimal_value)
        {
            optimal_value = a->value;
            optimal_position = a->position;
        }
        if (value < a->value && a->value < optimal_value)
        {
            optimal_value = a->value;
            optimal_position = a->position;
        }
        a = a->prev;
    }
    return (optimal_position);
}

void push_optimal_a(Node** a, Node** b)
{
    int opt_position;
    int a_length;
    int i;

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
    else {
        i = opt_position;
        while (a_length > i)
        {
            rra(a, 0);
            i++;
        }
    }
    pa(a, b);
}

void phase_two(Node** a, Node** b)
{
    while (*b)
        push_optimal_a(a, b);
}
