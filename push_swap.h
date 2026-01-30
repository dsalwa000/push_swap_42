/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:28:39 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/29 15:45:54 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include "libft/libft.h"
# define PUSH_SWAP_H

typedef struct Node
{
	int			    value;
	struct Node     *next;
    struct Node     *prev;
    int             position;
}					Node;
int     argv_length(char** argv);
int*    argv_int(char** argv, int argc, int length);
Node*   add_to_stack(Node* a, int value);
void    check_repetition(Node** a);
Node*   starting_stack(char** argv, int argc);

Node*   swap(Node* node);
void    sa(Node** a);
void    sb(Node** b);
void    ss(Node** a, Node** b);

void    push(Node**a, Node** b);
void    pa(Node** a, Node** b);
void    pb(Node** a, Node** b);

void    rotate(Node** node);
void    ra(Node **a, int rr);
void    rb(Node **b, int rr);
void    rr(Node **a, Node **b);

void    reverse_rotate(Node** node);
void    rra(Node **a, int rrr);
void    rrb(Node **b, int rrr);
void    rrr(Node **a, Node **b);

void    init_b(Node** a, Node** b);
void    determine_positions(Node* stack);
int     stack_length(Node *stack);
void    sort_three(Node** a);

Node*   find_min_node(Node* a);
int     find_optimal_a(Node* a, int value_b);
void    push_optimal_a(Node** a, Node** b);
void    push_all_to_a(Node** a, Node** b);

int     count_rb(Node* b, int a_value);
int*    a_cost(Node* node, int a_length);
int*    b_cost(Node* b, int a_value);
int*    combinations(Node* node, Node* b, int a_length);
int     costs(int* combinations, int return_type);

void    r_movement(Node** a, Node** b, int* bigger, int* smaller, int type);
void    rr_movement(Node** a, Node** b, int* bigger, int* smaller, int type);
void    type_two_movements(Node** a, Node** b, int* a_moves, int* b_moves);
void    type_three_movements(Node** a, Node** b, int* a_moves, int* b_moves);

int     find_optimal_b(Node* a, Node* b);
void    push_node_to_b(Node** a, Node** b, int* a_moves, int* b_moves, int type);
void    find_and_push_b(Node** a, Node** b);
void    push_all_to_b(Node **a, Node** b);

void    check_input_errors(char* digit, int** int_argv);
void    small_stack(Node** a, Node** b);
void    big_stack(Node** a, Node** b);

void    free_stack(Node** stack);
void    free_argv(char** argv);
void    exit_error();

int     ft_long_atoi(const char *nptr, int** argv_int);

// utils_functions.c
// only for testing, remove after!!!
void    display_stack(Node* stack, char ab);
void    display_stacks(Node *a, Node *b);
void    show_combinations(int* combinations);
void    show_moves(int* moves, char type);

#endif