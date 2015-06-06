/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_receive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:03:41 by lscopel           #+#    #+#             */
/*   Updated: 2015/06/06 13:19:17 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnetwork.h"

static int	choose_stuff(char *path, int fd)
{
	ft_putcolor("Existing file : ", 1);
	ft_putendl("Overwrite");
	close(fd);
	fd = open(path, O_TRUNC | O_WRONLY);
	return (fd);
}

int			s_create_file(char *path)
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

int			s_read_file(int socket, int fd, int size)
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

static int	fill_file(char *buff, char **path, int size, int socket)
{
	int		fd;
	int		ret;
	char	*good_path;

	ret = recv(socket, buff, 1023, 0);
	fd = 0;
	if (buff[0] != '\0' && size != 0)
	{
		buff[ret] = '\0';
		good_path = path[1];
		fd = s_create_file(good_path);
		if (fd <= 0)
			return (s_read_file(socket, fd, size));
		write(fd, buff, ft_strlen(buff));
		send(socket, "", 1, 0);
	}
	s_read_file(socket, fd, size);
	if (fd > 0 || size == 0)
	{
		close(fd);
		return (0);
	}
	else
		return (-1);
}

int			s_receive_file(char **path, int socket)
{
	int				ret;
	char			buff[1024];
	int				size;

	ft_bzero(buff, 1023);
	if ((ret = recv(socket, buff, 1023, 0)) == 0)
		return (0);
	if (!(ft_strcmp(buff, "file") == 0))
		return (0);
	ft_bzero(buff, 1023);
	send(socket, "", 1, 0);
	if ((ret = recv(socket, buff, 1023, 0)) == 0)
		return (0);
	if ((size = ft_atoi(buff)) == 0)
	{
		send(socket, "", 1, 0);
		ft_putendl("SUCCESS");
		return (s_create_file(path[1]));
	}
	else if (size == -1)
		return (report(2, socket));
	send(socket, "", 1, 0);
	return (fill_file(buff, path, size, socket));
}
