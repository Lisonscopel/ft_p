#include "client.h"

static void			no_action(int sock, char *fct)
{
	int		ret;
	char	buf[32768];
	int		ok;

	ok = 0;
	while ((ret = recv(sock, buf, 32767, 0)))
	{
		buf[ret] = '\0';
		if (ft_strncmp("ERROR ", buf, 6) != 0)
		{
			ok = 1;
			ft_putstr(buf);
		}
		else
			ft_putendl(buf + 6);
		if (ft_strcmp(fct, "ls") != 0 && ret < 32767)
			break ;
		else if (ft_strcmp(fct, "ls") == 0 && buf[0] == 4 && ret == 1)
			break ;
	}
	if (ok != 0)
		ft_putcolorendl("SUCCESS", 32);
	else
		ft_putcolorendl("ERROR", 31);

}

static char			*join_cmd(char **t)
{
	char	*rtn;
	int		i;

	i = 2;
	rtn = NULL;
	rtn = ft_strdup(t[0]);
	while (t[i])
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
	if (ft_strcmp(new_av[0], "get") == 0 && new_av[1] == NULL)
	{
		client_report(2, sock);
		return ;
	}
	if (ft_strcmp(new_av[0], "put") == 0 && new_av[1] == NULL)
	{
		client_report(3, sock);
		return ;
	}
	send(sock, line, ft_strlen(line), 0);
	while (tmp != NULL)
	{
		if (new_av[0] && ft_strcmp(tmp->name, new_av[0]) == 0)
		{
			int ret = tmp->ptr_funct(new_av, sock);
			if (ft_strcmp(tmp->name, "get") == 0 && new_av[2] != NULL)
				dial_server(sock, join_cmd(new_av));
			client_report(ret, 0);
			bool = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (bool == 0)
		no_action(sock, new_av[0]);
}
