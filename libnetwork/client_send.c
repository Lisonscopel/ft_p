/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_send.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:03:18 by lscopel           #+#    #+#             */
/*   Updated: 2015/06/06 13:15:33 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnetwork.h"

static int	avada_kedavra(int fd, int socket)
{
	char			buff[1];
	char			tmp[1024];
	char			*size;
	int				ret;
	struct stat		st;

	fstat(fd, &st);
	size = ft_itoa(st.st_size);
	send(socket, "file", 5, 0);
	recv(socket, tmp, 1024, 0);
	send(socket, size, ft_strlen(size), 0);
	recv(socket, tmp, 1024, 0);
	while ((ret = read(fd, buff, 1)) > 0)
	{
		send(socket, buff, ret, 0);
		recv(socket, tmp, 1024, 0);
	}
	close(fd);
	return (1);
}

int			c_send(char **path, int socket)
{
	char			tmp[1024];
	int				fd;

	if (path[1])
	{
		if ((fd = open(path[1], O_RDONLY)) != -1)
			return (avada_kedavra(fd, socket));
		else
		{
			send(socket, "file", 5, 0);
			recv(socket, tmp, 1024, 0);
			send(socket, "-1", 2, 0);
			recv(socket, tmp, 1024, 0);
			ft_putcolorendl("Pas de fichier", 31);
			return (-1);
		}
	}
	return (0);
}
