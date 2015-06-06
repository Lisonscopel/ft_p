/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_receive_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:03:41 by lscopel           #+#    #+#             */
/*   Updated: 2015/06/06 13:15:31 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnetwork.h"

static int			choose_stuff(char *path, int fd)
{
	char			*line;
	int				i;

	ft_putendl("\033[0;1mExisting file :\033[0m");
	ft_putstr("(A)bort, (R)ename, (O)verwrite ? ");
	if (get_next_line(0, &line) > 0)
	{
		if (ft_toupper(line[0]) == 'R')
		{
			ft_putstr("New name : ");
			i = get_next_line(0, &line);
			line = (i == 0) ? ft_strdup(path) : line;
			close(fd);
			return (c_create_file(line));
		}
		else if (ft_toupper(line[0]) == 'O')
		{
			close(fd);
			fd = open(path, O_TRUNC | O_WRONLY);
			return (fd);
		}
		free(line);
	}
	close(fd);
	return (0);
}

int					c_create_file(char *path)
{
	char			*good_path;
	int				fd;

	good_path = get_path(path);
	if ((fd = open(good_path, O_RDONLY)) != -1)
		return (choose_stuff(good_path, fd));
	else
	{
		fd = open(good_path, O_CREAT | O_WRONLY);
		return (fd);
	}
	return (0);
}

int					c_read_file(int socket, int fd, int size)
{
	char			buff[1024];
	int				ret;

	if (fd == 0)
		send(socket, "", 1, 0);
	while (size > 1)
	{
		ret = recv(socket, buff, 1023, 0);
		if (fd > 0)
			write(fd, buff, ret);
		size -= ret;
		send(socket, "", 1, 0);
	}
	return (0);
}
