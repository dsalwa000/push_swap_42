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

Node* find_min_node(Node* a)
{
    int     min_value;
    Node*   min_node;

    min_value = INT_MAX;
    min_node = NULL;
    while (a != NULL)
    {
        if (a->value < min_value)
        {
            min_value = a->value;
            min_node = a;
        }
        a = a->prev;
    }
    return (min_node);
}

int find_optimal_a(Node* a, int value_b)
{
    Node*   current_a;
    Node*   min_node;
    int     optimal_value;
    int     optimal_position;

    current_a = a;
    optimal_value = INT_MAX;
    optimal_position = 0;
    min_node = find_min_node(a);

    while(current_a)
    {
        if (current_a->value > value_b && current_a->value < optimal_value)
        {
            optimal_value = current_a->value;
            optimal_position = current_a->position;
        }
        current_a = current_a->prev;
    }
    if (optimal_value == INT_MAX)
        return (min_node->position);
    return (optimal_position);
}

void push_optimal_a(Node** a, Node** b)
{
    int     opt_position;
    int     a_length;
    int     i;

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
    Node*   min_node;
    int     a_length;
    while (*b)
        push_optimal_a(a, b);
    min_node = find_min_node(*a);
    a_length = stack_length(*a);
    if ((a_length / 2) >= min_node->position)
        while (*a != min_node)
            ra(a, 0);
    else
        while (*a != min_node)
            rra(a, 0);
}
