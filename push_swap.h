#ifndef PUSH_SWAP_H
# include "libft/libft.h"
# define PUSH_SWAP_H

void test();
typedef struct Node
{
	int			    value;
    int             index;
	struct node     *next;
    struct node     *prev;
    int             current_position;
}					Node;

#endif