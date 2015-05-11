/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 20:44:08 by tlepeche          #+#    #+#             */
/*   Updated: 2015/05/11 21:18:01 by tlepeche         ###   ########.fr       */
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

	int fd;
	char *tmp;

	if (ac != 3)
		ft_usage(av[0], " <addr> <port>");
	port = ft_atoi(av[2]);
	sock = client_create_tcp(av[1], port);
	while (1)
	{
		ft_putstr("client> ");
		ret = get_next_line(0, &line);
		if (line[0] != '\0')
		{
			send(sock, line, ft_strlen(line), 0);
			if (ft_strcmp(line, "quit") == 0)
			{
				ft_putendl("SUCCESS");
				break;
			}
			/////////////////////////// GET __FILE__ //////////////////////////
			// la fonction put __file__ c'est la meme mais dans l'autre sens //
			// ////////////////////////////////////////////////////////////////
			if (ft_strncmp(line, "get ", 4) == 0)
			{
				ret2 = recv(sock, buf2, 1024, 0);
				if (buf2[0] != '\0')
				{
					buf2[ret2] = '\0';
					if (how_many(line, '/') != 0)
					{
						tmp = ft_strnew(ft_strlen(line) + 1);
						tmp = ft_strrchr(line, '/');
						tmp = ft_strsub(tmp, 1, ft_strlen(tmp) - 1);
						fd = open(tmp, O_WRONLY | O_CREAT | O_TRUNC);
					}
					else
					{
						tmp = ft_strnew(ft_strlen(line) + 1);
						tmp = ft_strrchr(line, ' ');
						tmp = ft_strsub(tmp, 1, ft_strlen(tmp) - 1);
						fd = open(tmp, O_WRONLY | O_CREAT | O_TRUNC);
					}
					write(fd, buf2, ft_strlen(buf2));
					send(sock, "", 1, 0);
					while ((ret2 = recv(sock, buf2, 1024, 0)) > 0)
					{
						if (buf2[0] == '\0')
							break ;
						buf2[ret2] = '\0';
						line = ft_strjoin(buf2, "\n");
						write(fd, buf2, ft_strlen(buf2));
						send(sock, "", 1, 0);
					}
					ft_putendl("SUCCESS");
				}
				else
					ft_putendl("ERROR");
			}
			///////////////////////////
			else
			{
				ret2 = recv(sock, buf2, 1023, 0);
				buf2[ret2] = '\0';
				if (ft_strlen(buf2) != 0)
				{
					ft_putendl("SUCCESS");
					ft_putendl(buf2);
				}
				else
					ft_putendl("ERROR");
			}
		}
		free(line);
	}
	close(sock);
}
