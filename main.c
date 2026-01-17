/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:48:39 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/12 22:33:55 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char* argv[])
{
  Node*   a;
  // Node*   b;

  a = starting_stack(argv_int(argc - 1, argv), argc - 1);
  // b = NULL;
  display_stack(a, 'a');
  a = sa(a);
  display_stack(a, 'a');
  a = sa(a);
  display_stack(a, 'a');
  return 0;
}
