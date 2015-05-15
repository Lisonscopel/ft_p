#include "client.h"

static t_fct	*list_add(t_fct **list, char *name, int (*ptr_funct)())
{
	t_fct	*new;
	t_fct	*tmp;

	tmp = *list;
	new = (t_fct *)malloc(sizeof(t_fct));
	new->name = name;
	new->ptr_funct = ptr_funct;
	new->next = NULL;
	if (*list == NULL)
		return (new);
	else
	{
		while ((*list)->next != NULL)
			*list = (*list)->next;
	}
	(*list)->next = new;
	return (tmp);
}

void			init(t_fct **list)
{
	*list = NULL;
	*list = list_add(list, "quit", &(ask_quit));
	*list = list_add(list, "exit", &(ask_quit));
	*list = list_add(list, "get", &(ask_get));
}
