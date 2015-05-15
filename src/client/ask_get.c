/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 18:59:38 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/14 22:53:02 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int		create_file(char *path)
{
	char	*tmp;
	int		fd;

	if(ft_strchr(path, '/'))
	{
		tmp = ft_strrchr(path, '/');
		tmp++;
	}
	else
		tmp = path;
	if ((fd = open(tmp, O_RDONLY)) != -1)
		ft_putendl("Fichier existant");
	else
	{
		fd = open(tmp, O_CREAT | O_WRONLY);
		return (fd);
	}
	return (0);
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
		fd = create_file(path);
		if (fd <= 0)
		{
			send(sock, "\0", 1, 0);
			return (-1);
		}
		send(sock, "", 1, 0);
	}
	while((ret = recv(sock, buf, 1023, 0)) > 0)
	{
		if(buf[0] == '\0')
			break ;
		ft_putcolor(buf, 31);
		send(sock, "", 1, 0);
	}
	close(fd);
	return (0);
}
