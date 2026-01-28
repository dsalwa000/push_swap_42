/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:48:39 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/28 21:44:57 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 4, 3, 2, 1 sortuje zle
// -- puste argumenty
// krotkie listy
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
  if (stack_length(a) < 5)
    small_stack(&a, &b);
  else
  {
    init_b(&a, &b);
    // display_stack(a, 'a');
    // display_stack(b, 'b');
    push_all_to_b(&a, &b);
    sort_three(&a);
    push_all_to_a(&a, &b);
    display_stack(a, 'a');
    free_stack(&a);
  }
  return (0);
}
