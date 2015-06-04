#include "libft.h"

t_list	*ft_lstend(t_list *t)
{
	if (!t)
		return (NULL);
	while (t->next)
		t = t->next;
	return (t);
}
