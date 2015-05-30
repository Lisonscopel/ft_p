#include "server.h"

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
	*list = list_add(list, "ls", &(ask_list));
	*list = list_add(list, "cd", &(ask_cd));
	*list = list_add(list, "pwd", &(ask_pwd));
	*list = list_add(list, "get", &(s_send));
	*list = list_add(list, "put", &(s_receive_file));
	*list = list_add(list, "affiche_mon_prompt_steuple_thx_bye",\
			&(display_prompt));
	*list = list_add(list, "lcd", &(lcd));
	*list = list_add(list, "lpwd", &(lpwd));
	*list = list_add(list, "lls", &(lls));
}
