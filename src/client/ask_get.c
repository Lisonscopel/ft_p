/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 18:59:38 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/16 20:40:50 by vpailhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int		something(char *path)
{
	char	*tmp;
	char	*line;
	int		fd;

	if(ft_strchr(path, '/'))
	{
		tmp = ft_strrchr(path, '/');
		tmp++;
	}
	else
		tmp = path;
	if ((fd = open(tmp, O_RDONLY)) != -1)
	{
		ft_putendl("\e[0;1mExisting file :\e[0m\n(A)bort, (R)ename, (O)verwrite ?");
		get_next_line(0, &line);
		if (line[0] == 'R')
		{
			ft_putendl("New name : ");
			get_next_line(0, &line);
			return (something(line));
		}
		else if (line[0] == 'O')
		{
			fd = open(tmp, O_TRUNC | O_WRONLY);
			return (fd);
		}
		else
		{
			close(fd);
			return (-1);
		}
	}
	else
	{
		fd = open(tmp, O_CREAT | O_WRONLY);
		return (fd);
	}
	return (-1);
}

int				ask_get(char **new_av, int sock)
{
	int			ret;
	int			fd;
	char		buf[1024];
	char		*path;

	ret = recv(sock, buf, 1023, 0);
	if (buf[0] != '\0')
	{
		buf[ret] = '\0';
		path = new_av[1];
		fd = something(path);
		if (fd <= 0)
		{
			send(sock, "", 1, 0);
			while((ret = recv(sock, buf, 1023, 0)) > 0)
			{
				if(buf[0] == '\0')
					break ;
				send(sock, "", 1, 0);
			}
			return (-1);
		}
		write(fd, buf, ft_strlen(buf));
		send(sock, "", 1, 0);
	}
	while((ret = recv(sock, buf, 1023, 0)) > 0)
	{
		if(buf[0] == '\0')
			break ;
		write(fd, buf, ret);
		send(sock, "", 1, 0);
	}
	close(fd);
	return (0);
}
