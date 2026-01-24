#include "push_swap.h"

// chciałbym wykorzystać istniejące funkcje by
// nie musieć pisać kodu jeszcze raz
int effecient_a_node_position(Node* a, Node *b)
{
  int   final_position;
  int   efficient_cost;
  int   final_cost;
  int   a_length;
  int*  a_cost;
  int*  b_cost;

  a_cost = (int*)malloc(2 * sizeof(int));
  a_length = stack_length(a);
  final_position = 0;
  final_cost = INT_MAX;
  while (a != NULL)
  {
    b_cost = b_moves(b, a->value);
    a_cost[0] = a->position;
    a_cost[1] = a_length - a_cost[0];
    efficient_cost = costs(combinations(a_cost, b_cost));
    if (final_cost > efficient_cost)
    {
      final_cost = efficient_cost;
      final_position = a->position;
    }
    a = a->prev;
  }
  printf("operations: %d\n", final_cost);
  return (final_position);
}
