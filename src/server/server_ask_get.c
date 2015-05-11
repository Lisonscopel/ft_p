/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_ask_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 17:38:07 by tlepeche          #+#    #+#             */
/*   Updated: 2015/05/11 21:08:43 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int ask_get(char **av, int fd)
{
	char	*line;
	int		tar_fd;

	if (av[1])
	{
		tar_fd = open(av[1], O_RDONLY);
		if (tar_fd != -1)
		{
			while (get_next_line(tar_fd, &line) > 0)
			{
				line = ft_strjoin(line, "\n");
				send(fd, line, ft_strlen(line) + 1, 0);
				recv(fd, line, 1, 0);
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
