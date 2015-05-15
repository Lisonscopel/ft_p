/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_ask_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 17:38:07 by tlepeche          #+#    #+#             */
/*   Updated: 2015/05/15 19:45:52 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int ask_get(char **av, int fd)
{
	char		buff[255];
	char		tmp;
	int			tar_fd;
	int			ret;
	struct stat st;

	if (av[1])
	{
		tar_fd = open(av[1], O_RDONLY);
		if (tar_fd != -1)
		{
			fstat(tar_fd, &st);
			while ((ret = read(tar_fd, buff, 255)) > 0)
			{
				send(fd, buff, ret, 0);
				recv(fd, &tmp, 1, 0);
			}
			send(fd, "\0", 1, 0);
			close(tar_fd);
			return (1);
		}
		send(fd, "\0", 1, 0);
		return (0);
	}
	return (0);
}
