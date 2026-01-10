#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*position;

	if (!lst)
		return (NULL);
	position = lst;
	while (position->next != NULL)
		position = position->next;
	return (position);
}
