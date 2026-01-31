/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:00:44 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/30 21:38:25 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_length(char **argv)
{
	int	length;

	length = 0;
	while (argv[length] != NULL)
	{
		length++;
	}
	if (ft_strncmp(argv[0], "./push_swap", 12) == 0)
		length--;
	return (length);
}

int	*argv_int(char **argv, int argc, int length)
{
	int	i;
	int	*int_argv;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	int_argv = (int *)malloc(length * sizeof(int));
	while (argv[i] != NULL)
	{
		check_input_errors(argv[i], &int_argv);
		if (argc == 2)
			int_argv[i] = ft_long_atoi(argv[i], &int_argv);
		else
			int_argv[i - 1] = ft_long_atoi(argv[i], &int_argv);
		i++;
	}
	return (int_argv);
}

t_node	*add_to_stack(t_node *a, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->value = value;
	new_node->next = NULL;
	if (a == NULL)
	{
		new_node->prev = NULL;
	}
	else
	{
		a->next = new_node;
		new_node->prev = a;
	}
	return (new_node);
}

void	check_repetition(t_node **a)
{
	t_node	*iterate;

	iterate = (*a)->prev;
	while (iterate != NULL)
	{
		if (iterate->value == (*a)->value)
		{
			free_stack(a);
			exit_error();
		}
		iterate = iterate->prev;
	}
}

t_node	*initiate_a(char **argv, int argc)
{
	t_node	*a;
	int		*int_argv;
	int		i;
	int		length;
	int		is_sorted;

	a = NULL;
	i = 0;
	length = argv_length(argv);
	int_argv = argv_int(argv, argc, length);
	is_sorted = 1;
	while (length > i)
	{
		a = add_to_stack(a, int_argv[length - i - 1]);
		check_repetition(&a);
		if (a->prev != NULL)
			if (a->value > a->prev->value)
				is_sorted = 0;
		i++;
	}
	free(int_argv);
	if (is_sorted)
		exit(0);
	determine_positions(a);
	return (a);
}
