#include "server.h"

static void	list_add(t_fct **list, char *name, void (*ptr_fnc)())
{
	t_fct	*new;

	new = (t_fct *)malloc(sizeof(t_fct));
	if (new != NULL)
	{
		new->name = name;
		new->ptr_fnc = ptr_fnc;
		if (*list == NULL)
			new->next = NULL;
		else
			new->next = *list;
		*list = new;
	}
}

void		init(t_fct **list)
{
	t_fct	*list;
	list = NULL;

	list_add(list, "ls", &(ask_list));
	list_add(list, "bonjour", &(ask_bonjour));
	list_add(list, "pwd", &(ask_pwd));
	list_add(list, "quit", &(ask_quit));
}