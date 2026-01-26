/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:28:39 by dsalwa            #+#    #+#             */
/*   Updated: 2026/01/20 20:28:40 by dsalwa           ###   ########.fr       */
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
int     argv_int_length(int *argv);
int*    argv_int(char** argv, int argc, int length);
Node*   starting_stack(char** argv, int argc);
Node*   add_to_stack(Node* a, int value);

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

int     rb_moves(Node* b, int a_value);
int*    a_cost(Node* node, int a_length);
int*    b_cost(Node* b, int a_value);
int*    combinations(Node* node, Node* b, int a_length);
int     costs(int* combinations, int return_type);

void    init_b(Node** a, Node** b);

void    r_movement(Node** a, Node** b, int* bigger, int* smaller, int type);
void    rr_movement(Node** a, Node** b, int* bigger, int* smaller, int type);
void    type_two_movements(Node** a, Node** b, int* a_moves, int* b_moves);
void    type_three_movements(Node** a, Node** b, int* a_moves, int* b_moves);

int     effecient_a_node_position(Node* a, Node* b);
void    determine_positions(Node* stack);
int     stack_length(Node* stack);
void    sort_three(Node** a);
void    move_to_b(Node** a, Node** b, int* a_moves, int* b_moves, int type);
void    use_efficent_position(Node** a, Node** b);
void    phase_one(Node **a, Node** b);

// utils_functions.c
// only for testing, remove after!!!
void    display_stack(Node* stack, char ab);
void    display_stacks(Node *a, Node *b);
void    show_combinations(int* combinations);
void    show_moves(int* moves, char type);

#endif