#include "server.h"

void	dial_client(int cs)
{
	int					ret;
	int					bool;
	char				**new_av;
	char				buf[1024];
	t_fct				*list;
	t_fct				*tmp;
	int					ret_val;

	init(&list);
	while ((ret = recv(cs, buf, 1023, 0)) > 0)
	{
		tmp = list;
		buf[ret] = '\0';
		new_av = ft_strsplit_blank(buf);
		bool = 0;
		while (tmp != NULL)
		{
			if (new_av[0] && ft_strcmp(tmp->name, new_av[0]) == 0)
			{
				ret_val = tmp->ptr_funct(new_av, cs);
				bool = 1;
				break ;
			}
			tmp = tmp->next;
		}
/*		ft_putstr("bool/retour: ");
		ft_putnbr(bool);
		ft_putchar(' ');
		ft_putnbr(ret_val);
		ft_putchar('\n');
*/		// 	else if (ft_strcmp(new_av[0], "bonjour") == 0)
		// 		send(cs, "Salut", ft_strlen("salut"), 0);
		if (bool == 0 || ret_val == 0)
			send(cs, "", 1, 0);
	 	ft_putstr("received ");
	 	ft_putnbr(ret);
	 	ft_putstr(" bytes: ");
	 	ft_putendl(buf);
		ft_free_tab(new_av);
	}
}
