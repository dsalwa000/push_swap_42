/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:43:39 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/29 16:02:41 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// trzeba sprawdzic jeszcze samego minusa oraz arguemnty wieksze oraz mniejsze od INT_MAX i INT_MIN
void check_if_digit(char* digit, int** argv_int)
{
    int minuses;

    minuses = 0;
    while (*digit != '\0')
    {
        if (*digit == '-')
            minuses++;
        else
            minuses = 0;
        if ((!ft_isdigit(*digit) && *digit != '-') || minuses > 1)
        {
            free(*argv_int);
            write(2, "Error\n", 6);
            exit(1);
        }
        digit++;
    }
}

void small_stack(Node** a, Node** b)
{
    int     a_length;

    a_length = stack_length(*a);
    if (a_length == 2)
    {
        if ((*a)->value > (*a)->prev->value)
            ra(a, 0);
    }
    else if (a_length == 3)
        sort_three(a);
    else if (a_length == 4)
    {
        pb(a, b);
        sort_three(a);
        push_all_to_a(a, b);
    }
}

void big_stack(Node** a, Node** b)
{
    init_b(a, b);
    push_all_to_b(a, b);
    sort_three(a);
    push_all_to_a(a, b);
}

