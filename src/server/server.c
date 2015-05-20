/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 17:22:10 by sduprey           #+#    #+#             */
/*   Updated: 2015/05/20 18:27:06 by vpailhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int						server_login(int sock)
{
	int		ret = 0;
	char	buff[1024];

	while ((ft_strcmp(buff, "okcbon"))) 
	{
		ret = recv(sock, buff, 1023, 0);
		buff[ret] = 0;
	}
	ft_putendl("A");
	send(sock, "wfyl", 5, 0);
	ret = recv(sock, buff, 1023, 0);
	buff[ret] = 0;
	ft_putendl(buff);
	//ft_strcmp(buff, )
	return (0);
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
			if (!(server_login(sock)))
				exit(0);
			dial_client(cs);
			close(cs);
			exit(0);
		}
	}
	close(sock);
	exit(0);
}
