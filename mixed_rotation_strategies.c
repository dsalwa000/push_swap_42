#include "push_swap.h"

void	type_two_movements(t_node **a, t_node **b, int *a_moves, int *b_moves)
{
	int	i;

	i = 0;
	while (a_moves[0] > i)
	{
		ra(a, 0);
		i++;
	}
	i = 0;
	while (b_moves[1] > i)
	{
		rrb(b, 0);
		i++;
	}
}

void	type_three_movements(t_node **a, t_node **b, int *a_moves, int *b_moves)
{
	int	i;

	i = 0;
	while (a_moves[1] > i)
	{
		rra(a, 0);
		i++;
	}
	i = 0;
	while (b_moves[0] > i)
	{
		rb(b, 0);
		i++;
	}
}
