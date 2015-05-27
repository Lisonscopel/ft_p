#include "client.h"

static void			no_action(int sock)
{
	int		ret;
	char	buf[32768];

		while ((ret = recv(sock, buf, 32767, 0)))
		{
			buf[ret] = '\0';
			if (ft_strncmp("ERROR ", buf, 6) != 0)
			{
				ft_putcolorendl("SUCCESS", 32);
				ft_putstr(buf);
			}
			else
			{
				ft_putcolorendl("ERROR", 31);
				ft_putendl(buf + 6);
			}
			if (ret < 32767)
				break ;
		}
}

static char			*join_cmd(char **t)
{
	char	*rtn;
	int		i;

	i = 2;
	while(t[i])
	{
		rtn = ft_strjoin(rtn, " ");
		rtn = ft_strjoin(rtn, t[i]);
		i++;
	}
	return (rtn);
}

void				dial_server(int sock, char *line)
{
	t_fct	*list;
	int		bool;
	t_fct	*tmp;
	char	**new_av;

	bool = 0;
	init(&list);
	tmp = list;
	new_av = ft_strsplit_blank(line);
	send(sock, line, ft_strlen(line), 0);
	while (tmp != NULL)
	{
		if (new_av[0] && ft_strcmp(tmp->name, new_av[0]) == 0)
		{
			tmp->ptr_funct(new_av, sock);
			if (ft_strcmp(tmp->name, "get") == 0 && new_av[2] != NULL)
				dial_server(sock, join_cmd(new_av));
			bool = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (bool == 0)
		no_action(sock);
}
