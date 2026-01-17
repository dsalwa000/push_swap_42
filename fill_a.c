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
    a = add_to_stack(a, int_argv[i]);
    i++;
  }
  return (a);
}

Node *add_to_stack(Node* a, int value)
{
  Node*   newNode;
  
  newNode = (Node*)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  if (a == NULL)
  {
    newNode->position = 0;
    newNode->prev = NULL;
  }
  else
  {
    a->next = newNode;
    newNode->position = a->position + 1;
    newNode->prev = a;
  }
  return (newNode);
}

// only for testing, remove after!!!
void display_stack(Node* stack, char ab)
{
  while (stack->prev != NULL)
    stack = stack->prev;
  while (stack->next != NULL)
  {
    printf("%d\n", stack->value);
    stack = stack->next;
  }
  printf("%d\n", stack->value);
  printf("_\n%c\n", ab);
}