#include "server.h"

static void	list_add(t_fct **list, char *name, int (*ptr_fnc)())
{
	t_fct	*new;

	new = (t_fct *)malloc(sizeof(t_fct));
	if (new != NULL)
	{
		new->name = name;
		new->ptr_funct = ptr_fnc;
		if (*list == NULL)
			new->next = NULL;
		else
			new->next = *list;
		*list = new;
	}
}

void		init(t_fct **list)
{
	*list = NULL;
	list_add(list, "ls", &(ask_list));
	list_add(list, "bonjour", &(ask_bonjour));
	list_add(list, "pwd", &(ask_pwd));
	list_add(list, "quit", &(ask_quit));
}