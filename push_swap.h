/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:28:39 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/30 22:03:08 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include "libft/libft.h"
# define PUSH_SWAP_H

typedef struct t_node
{
	int				value;
	struct t_node	*next;
	struct t_node	*prev;
	int				position;
}	t_node;
int		argv_length(char **argv);
int		*argv_int(char **argv, int argc, int length);
t_node	*add_to_stack(t_node *a, int value);
void	check_repetition(t_node **a);
t_node	*initiate_a(char **argv, int argc);
t_node	*swap(t_node *node);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	push(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	rotate(t_node **node);
void	ra(t_node **a, int rr);
void	rb(t_node **b, int rr);
void	rr(t_node **a, t_node **b);
void	reverse_rotate(t_node **node);
void	rra(t_node **a, int rrr);
void	rrb(t_node **b, int rrr);
void	rrr(t_node **a, t_node **b);
void	init_b(t_node **a, t_node **b);
void	determine_positions(t_node *stack);
int		stack_length(t_node *stack);
void	sort_three(t_node **a);
t_node	*find_min_node(t_node *a);
int		find_optimal_a(t_node *a, int value_b);
void	push_optimal_a(t_node **a, t_node **b);
void	push_all_to_a(t_node **a, t_node **b);
int		count_rb(t_node *b, int a_value);
int		*a_cost(t_node *node, int a_length);
int		*b_cost(t_node *b, int a_value);
int		*comb(t_node *node, t_node *b, int a_length);
int		costs(int *combinations, int return_type);
void	rr_ra(t_node **a, t_node **b, int *bigger, int *smaller);
void	rr_rb(t_node **a, t_node **b, int *bigger, int *smaller);
void	rrr_rra(t_node **a, t_node **b, int *bigger, int *smaller);
void	rrr_rrb(t_node **a, t_node **b, int *bigger, int *smaller);
void	type_two_movements(t_node **a, t_node **b, int *a_moves, int *b_moves);
void	type_three_movements(t_node **a, t_node **b, int *a_moves, int *b_moves);
int		find_optimal_b(t_node *a, t_node *b, int a_length);
void	push_node_to_b(t_node **a, t_node **b, t_node *optimal, int type);
void	find_and_push_b(t_node **a, t_node **b);
void	push_all_to_b(t_node **a, t_node **b);
void	check_input_errors(char *digit, int **int_argv);
void	small_stack(t_node **a, t_node **b);
void	big_stack(t_node **a, t_node **b);
void	free_stack(t_node **stack);
void	free_argv(char **argv);
void	exit_error(void);
int		ft_long_atoi(const char *nptr, int **argv_int);

#endif
