/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:48:39 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/20 20:31:35 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char* argv[])
{
  Node*   a;
  Node*   b;

  if (argc == 1 || (argc == 2 && !argv[1][0]))
    return (1);
  else if (argc == 2)
    argv = ft_split(argv[1], ' ');
  a = starting_stack(argv, argc);
  b = NULL;
  init_b(&a, &b);
  display_stacks(a, b);
  phase_one(&a, &b);
  display_stacks(a, b);
  sort_three(&a);
  display_stacks(a, b);
  return 0;
}
