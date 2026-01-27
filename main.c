/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:48:39 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/26 21:09:16 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// reszta na jutro

// alerty dotyczące kodu:
// -- duplikaty (DONE)
// -- wartosci poza INT
// -- znaki inne niz cyfry ( w tym + - samo)
// -- puste argumenty
// write(2, "Error\n", 6);
// exit(1); // Pamiętaj o zwolnieniu pamięci przed exit!
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
  push_all_to_b(&a, &b);
  sort_three(&a);
  push_all_to_a(&a, &b);
  display_stack(a, 'a');
  free_stack(&a);
  return 0;
}
