/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:00:44 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/20 20:22:09 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int argv_length(char** argv)
{
  int   length;

  length = 0;    
  while (argv[length] != NULL)
  {
    length++;
  }
  if (ft_strncmp(argv[0], "./push_swap", 12) == 0)
    length--;
  return (length);
}

int* argv_int(char** argv, int argc, int length)
{
  int     i;
  int*    int_argv;

  if (argc == 2)
    i = 0;
  else
    i = 1;
  int_argv = (int*)malloc(length * sizeof(int));
  while (argv[i] != NULL)
  {
    if (argc == 2)
      int_argv[i] = ft_atoi(argv[i]);
    else
      int_argv[i - 1] = ft_atoi(argv[i]);
    i++;
  }
  return (int_argv);
}

Node* add_to_stack(Node* a, int value)
{
  Node*   newNode;
  
  newNode = (Node*)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  if (a == NULL)
  {
    newNode->prev = NULL;
  }
  else
  {
    a->next = newNode;
    newNode->prev = a;
  }
  return (newNode);
}

void check_repetition(Node** a)
{
  Node*   iterate;

  iterate = (*a)->prev;
  while (iterate != NULL)
  {
    if (iterate->value == (*a)->value)
    {
      free_stack(a);
      exit(1);
    }
    iterate = iterate->prev;
  }
}

Node* starting_stack(char** argv, int argc)
{
  Node* a;
  int   i;
  int*  int_argv;
  int   length;

  a = NULL;
  i = 0;
  length = argv_length(argv);
  int_argv = argv_int(argv, argc, length);
  while (length > i)
  {
    a = add_to_stack(a, int_argv[length - i - 1]);
    check_repetition(&a);
    i++;
  }
  free(int_argv);
  determine_positions(a);
  return (a);
}
