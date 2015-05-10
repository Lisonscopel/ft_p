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

#include "ft_p.h"

void	usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putendl(" <addr> <port>");
	exit (-1);
}

int		create_client(char *addr, int port)
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
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr("Connection error\n");
		exit (2);
	}
	return (sock);
}

int		main(int ac, char **av)
{
	int		port;
	int		sock;
	int		ret2;
	int		ret;
	char	buf2[1024];
	char	*line;

	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);
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
