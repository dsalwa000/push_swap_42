/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:00:44 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/20 19:52:48 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int argv_length(char **argv)
{
  int   length;

  length = 0;
  while (argv[length] != NULL)
  {
    length++;
  }
  return (length);
}

int* argv_int(char** argv, int argc)
{
  int   i;
  int*  int_argv;

  if (argc == 2)
    i = 0;
  else
    i = 1;
  int_argv = (int*)malloc(argv_length(argv) * sizeof(int));
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

Node* starting_stack(int* int_argv, int length, int argc)
{
  printf("length: %d\n", length);
  Node* a;
  int   i;

  i = 0;
  a = NULL;
  if (argc != 2)
    length--;
  while (length > i)
  {
    a = add_to_stack(a, int_argv[length - i - 1], length - i - 1);
    i++;
  }
  return (a);
}

Node* add_to_stack(Node* a, int value, int position)
{
  Node*   newNode;
  
  newNode = (Node*)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  newNode->position = position;
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
