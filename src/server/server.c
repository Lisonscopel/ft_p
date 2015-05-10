/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 17:22:10 by sduprey           #+#    #+#             */
/*   Updated: 2015/05/10 02:05:08 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h" 

void	usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putendl(" <port>");
	exit (-1);
}

int		create_serv(int port)
{
	int					sock;
	struct protoent		*prot;
	struct sockaddr_in	sin;

	prot = getprotobyname("tcp");
	if (!prot)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, prot->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr("Bind error\n");
		exit (2);
	}
	listen(sock, 42);
	return (sock);
}

int		main(int ac, char **av)
{
	int					port;
	int					sock;
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	int					ret;
	char				buf[1024];
	int					stop;

	char				**new_av;
	pid_t				father;

	char				*pwd;

	if (ac != 2)
		usage(av[0]);
	stop = 0;
	port = ft_atoi(av[1]);
	sock = create_serv(port);
	cs = accept(sock, (struct sockaddr *)&csin, &cslen);
	while ((ret = recv(cs, buf, 1023, 0)) > 0)
	{
		buf[ret] = '\0';
		new_av = ft_strsplit_blank(buf);
		if (new_av[0])
		{
			if (ft_strcmp(new_av[0], "ls") == 0)
			{
				father = fork();
				if (father > 0)
					wait4(father, 0, 0, 0);
				if (father == 0)
				{
					dup2(cs, 1);
					if (execv("/bin/ls", new_av) == -1)
						exit(0);
				}
			}
			else if (ft_strcmp(new_av[0], "bonjour") == 0)
				send(cs, "Salut", ft_strlen("salut"), 0);
			else if (!new_av[1] && ft_strcmp(new_av[0], "pwd") == 0)
			{
				pwd = (char *)malloc(sizeof(char) * 1024);
				pwd = getcwd(pwd, 1024);
				send(cs, pwd, ft_strlen(pwd), 0);
			}
			else
				send(cs, "", 1, 0);
			ft_putstr("received ");
			ft_putnbr(ret);
			ft_putstr(" bytes: ");
			ft_putendl(buf);
			free_tab(new_av);
		}
	}
	close(cs);
	close(sock);
}
