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
int     argv_length(char **argv);
int*    argv_int(char** argv, int argc);
Node*   starting_stack(int* int_argv, int length, int argc);
Node*   add_to_stack(Node* a, int value, int position);

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

void determine_positions(Node* stack);

// utils_functions.c
// only for testing, remove after!!!
void    display_stack(Node* stack, char ab);

#endif