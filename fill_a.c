#include "push_swap.h"

int* argv_int(int length, char** argv)
{
  int   i;
  int*  int_argv;

  i = 1;
  int_argv = (int*)malloc(length * sizeof(int));
  while (argv[i] != NULL)
  {
    int_argv[i - 1] = ft_atoi(argv[i]);
    i++;
  }
  return (int_argv);
}

Node* starting_stack(int* int_argv, int length)
{
  Node* a;
  int   i;

  i = 0;
  a = NULL;
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
