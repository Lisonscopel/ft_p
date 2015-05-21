/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 17:22:10 by sduprey           #+#    #+#             */
/*   Updated: 2015/05/21 16:02:21 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int						server_login(int sock)
{
	int		ret = 0;
	char	buff[1024];
	char	*line = NULL;
	int		fd;

	while (1) 
	{
		ret = recv(sock, buff, 1023, 0);
		if (!(ft_strcmp(buff, "okcbon"))) 
			break ;
	}
	send(sock, "wfyl", 4, 0);
	ret = recv(sock, buff, 1023, 0);
	fd = open(".log", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(ft_strcmp(line, buff)))
		{
			send(sock, "gotit", 5, 0);
			return (0);
		}
	}
	send(sock, "shameonyou", 10, 0);
	return (-1);
}

int						main(int ac, char **av)
{
	int					port;
	int					sock;
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;

	if (ac != 2)
		ft_usage(av[0], " <port>");
	port = ft_atoi(av[1]);
	sock = serv_create_tcp(port);
	while (42)
	{
		cs = accept(sock, (struct sockaddr *)&csin, &cslen);
//		prompt_display(cs);
		if (fork()  == 0)
		{
			if ((server_login(cs)) == -1)
			{
				close(cs);
				close(sock);
				exit(0);
				return (-1);
			}
			dial_client(cs);
			close(cs);
			exit(0);
		}
	}
	close(sock);
	exit(0);
}
