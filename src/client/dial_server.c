#include "client.h"

void	dial_server(int sock, char *line)
{
	t_fct	*list;
	int		bool;
	t_fct	*tmp;
	char	**new_av;
	int		ret_val;
	char	buf[1024];
	int		ret;

	bool = 0;
	init(&list);
	tmp = list;
	new_av = ft_strsplit_blank(line);
	send(sock, line, ft_strlen(line), 0);
	while (tmp != NULL)
	{
		if (new_av[0] && ft_strcmp(tmp->name, new_av[0]) == 0)
		{
			ret_val = tmp->ptr_funct(new_av, sock);
			bool = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (bool == 0)
	{
		ret = recv(sock, buf, 1023, 0);
		buf[ret] = '\0';
		if (ft_strlen(buf) != 0)
		{
			ft_putendl(buf);
			ft_putendl("SUCCESS");
		}
		else
			ft_putcolorendl("ERROR", 31);
	}
}