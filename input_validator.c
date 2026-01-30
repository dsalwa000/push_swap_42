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

void check_input_errors(char* dig, int** argv_int)
{
    if (ft_strlen(dig) == 1 && dig[0] == '-')
    {
        free(*argv_int);
        exit_error();
    }
    if (ft_strlen(dig) > 1)
    {
        if (dig[0] == '0')
        {
            free(*argv_int);
            exit_error();
        }
        if (dig[0] == '-' && dig[1] == '0')
        {
            free(*argv_int);
            exit_error();
        }
    }
}

int ft_long_atoi(const char *nptr, int** argv_int)
{
    int   positive;
    long    result;

    while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
        nptr++;
    positive = 1;
    result = 0;
    if (*nptr == '-')
    {
        positive = -1;
        nptr++;
    }
    while (*nptr != '\0')
    {
        if (*nptr < '0' || *nptr > '9')
        {
            free(*argv_int);
            exit_error();
        }
        result = result * 10 + (*nptr - 48);
        nptr++;
    }
    if (result * positive > INT_MAX || result * positive < INT_MIN)
        exit_error();
    return (int)(result * positive);
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
