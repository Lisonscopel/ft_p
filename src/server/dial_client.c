#include "server.h"

void	dial_client(int cs, t_fct *list)
{
	int					ret;
	int					ask_ret;
	char				**new_av;
	char				buf[1024];
	t_fct				*tmp;


	while ((ret = recv(cs, buf, 1023, 0)) > 0)
	{
		buf[ret] = '\0';
		new_av = ft_strsplit_blank(buf);
		tmp = list;
		ask_ret = 0;
		while (tmp != NULL)
		{
			if (new_av[0] && ft_strcmp(tmp->name, new_av[0]) == 0)
			{

				ask_ret = tmp->ptr_funct(new_av, cs);
				break ;
			}
			tmp = tmp->next;
		}
	if (ask_ret <= 0)
			send(cs, "", 1, 0);
	 	ft_putstr("received ");
	 	ft_putnbr(ret);
	 	ft_putstr(" bytes: ");
	 	ft_putendl(buf);
		ft_free_tab(new_av);
	}
}