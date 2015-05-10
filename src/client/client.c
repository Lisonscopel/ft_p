/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 20:44:08 by tlepeche          #+#    #+#             */
/*   Updated: 2015/05/10 02:20:08 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		main(int ac, char **av)
{
	int		port;
	int		sock;
	int		ret2;
	int		ret;
	char	buf2[1024];
	char	*line;

	if (ac != 3)
		ft_usage(av[0], " <addr> <port>");
	port = ft_atoi(av[2]);
	sock = client_create_tcp(av[1], port);
	while (1)
	{
		ft_putstr("client> ");
		ret = get_next_line(0, &line);
		send(sock, line, ft_strlen(line), 0);
		if (ft_strcmp(line, "quit") == 0)
		{
			ft_putendl("SUCCESS");
			break;
		}
		ret2 = recv(sock, buf2, 1023, 0);
		buf2[ret2] = '\0';
		if (ft_strlen(buf2) != 0)
		{
			ft_putendl("SUCCESS");
			ft_putendl(buf2);
		}
		else
			ft_putendl("ERROR");
		free(line);
	}
	close(sock);
}
