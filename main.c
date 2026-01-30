/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:48:39 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/30 21:41:39 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int		split_done;

	split_done = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit_error();
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		split_done = 1;
	}
	a = starting_stack(argv, argc);
	b = NULL;
	if (stack_length(a) < 5)
		small_stack(&a, &b);
	else
		big_stack(&a, &b);
	if (split_done)
		free_argv(argv);
	free_stack(&a);
	return (0);
}
