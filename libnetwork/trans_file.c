/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpailhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 19:08:02 by vpailhe           #+#    #+#             */
/*   Updated: 2015/05/17 02:04:35 by vpailhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnetwork.h"

int					send_file(char **path, int socket)
{
	char			buff[255];
	char			tmp;
	int				fd;
	int				ret;
	struct stat		st;

	if (path[1])
	{
		if ((fd = open(path[1], O_RDONLY)) != -1)
		{
			fstat(fd, &st);
			while ((ret = read(fd, buff, 255)) > 0)
			{
				send(socket, buff, ret, 0);
				recv(socket, &tmp, 1, 0);
			}
			send(socket, "\0", 1, 0);
			close(fd);
			return (1);
		}
		send(socket, "\0", 1, 0);
	}
	return (0);
}

static char			*get_path(char *s)
{
	char			*ret;

	if (ft_strchr(s, '/'))
	{
		ret = ft_strrchr(s, '/');
		ret++;
	}
	else
		ret = s;
	return (ret);
}

static int			chose_stuff(char *path, int fd)
{
	char			*line;

	ft_putendl("\033[0;1mExisting file :\033[0m");
	ft_putstr("(A)bort, (R)ename, (O)verwrite ? ");
	get_next_line(0, &line);
	if (line[0] == 'R')
	{
		ft_putstr("New name : ");
		get_next_line(0, &line);
		close(fd);
		return (create_file(line));
	}
	else if (line[0] == 'O')
	{
		close(fd);
		fd = open(path, O_TRUNC | O_WRONLY);
		return (fd);
	}
	else
		close(fd);
	return (-1);
}

int					create_file(char *path)
{
	char			*good_path;
	int				fd;

	good_path = get_path(path);
	if ((fd = open(good_path, O_RDONLY)) != -1)
		return (chose_stuff(good_path, fd));
	else
	{
		fd = open(good_path, O_CREAT | O_WRONLY);
		return (fd);
	}
	return (-1);
}

static int			read_file(int socket, int fd)
{
	char			buff[1024];
	int				ret;

	if (fd == 0)
		send(socket, "", 1, 0);
	while ((ret = recv(socket, buff, 1023, 0)) >= 0)
	{
		if (buff[0] == '\0')
			break ;
		if (fd > 0)
			write(fd, buff, ret);
		send(socket, "", 1, 0);
	}
	return (-1);
}

int					recieve_file(char **path, int socket)
{
	int				ret;
	int				fd;
	char			buff[1024];
	char			*good_path;

	if ((ret = recv(socket, buff, 1023, 0)) == 0)
		return (0);
	fd = 0;
	if (buff[0] != '\0')
	{
		buff[ret] = '\0';
		good_path = path[1];
		fd = create_file(good_path);
		if (fd <= 0)
			return (read_file(socket, fd));
		write(fd, buff, ft_strlen(buff));
		send(socket, "", 1, 0);
	}
	read_file(socket, fd);
	if (fd > 0)
	{
		ft_putendl("SUCCESS");
		close(fd);
	}
	else
		ft_putendl("ERROR");
	return (0);
}
