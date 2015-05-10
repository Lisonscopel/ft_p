#include "server.h"

void	dial_client(int cs)
{
	int					ret;
	int					bool;
	char				**new_av;
	char				buf[1024];
	t_fct				*list;

	init(&list);


	while ((ret = recv(cs, buf, 1023, 0)) > 0)
	{
		buf[ret] = '\0';
		new_av = ft_strsplit_blank(buf);
		bool = 0;
		while (list != NULL)
		{
			if (new_av[0] && ft_strcmp(list->name, new_av[0]) == 0)
			{

				list->ptr_funct(new_av, cs);
				bool = 1;
				break ;
			}
			list = list->next;
		}
		// if (new_av[0])
		// {
		// 	if (ft_strcmp(new_av[0], "ls") == 0)
		// 	{
		// 		father = fork();
		// 		if (father > 0)
		// 			wait4(father, 0, 0, 0);
		// 		if (father == 0)
		// 		{
		// 			dup2(cs, 1);
		// 			if (execv("/bin/ls", new_av) == -1)
		// 				exit(0);
		// 		}
		// 	}
		// 	else if (ft_strcmp(new_av[0], "bonjour") == 0)
		// 		send(cs, "Salut", ft_strlen("salut"), 0);
		// 	else if (!new_av[1] && ft_strcmp(new_av[0], "pwd") == 0)
		// 	{
		// 		pwd = (char *)malloc(sizeof(char) * 1024);
		// 		pwd = getcwd(pwd, 1024);
		// 		send(cs, pwd, ft_strlen(pwd), 0);
		// 	}
		if (bool == 0)
			send(cs, "", 1, 0);
	 	ft_putstr("received ");
	 	ft_putnbr(ret);
	 	ft_putstr(" bytes: ");
	 	ft_putendl(buf);
		ft_free_tab(new_av);
	}
}