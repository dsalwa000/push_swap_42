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
int*    argv_int(int length, char** argv);
Node*   starting_stack(int* int_argv, int length);
Node    *add_to_stack(Node* a, int value);

// only for testing, remove after!!!
void    display_stack(Node* stack, char ab);

#endif