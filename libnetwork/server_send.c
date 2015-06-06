/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_send.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:03:18 by lscopel           #+#    #+#             */
/*   Updated: 2015/06/06 13:15:50 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnetwork.h"

void			do_the_sub_thing(t_deg *l)
{
	int		ret;

	send(l->socket, "getready", 8, 0);
	ret = recv(l->socket, l->buff, 1024, 0);
	l->buff[ret] = 0;
	send(l->socket, l->tmp_path[1], ft_strlen(l->tmp_path[1]), 0);
	ret = recv(l->socket, l->buff, 2, 0);
	send_unique_file(l->tmp_path, l->socket);
}

int				do_the_thing(t_deg *l)
{
	int				ret;

	l->tmp_path[1] = ft_strdup(l->s->d_name);
	if ((ret = chdir(l->tmp_path[1]) != -1))
	{
		if (ft_strcmp(l->tmp_path[1], "..") == 0)
			ret = chdir(l->path[1]);
		else if (ft_strcmp(l->tmp_path[1], ".") != 0)
		{
			chdir("..");
			send_dir(l->tmp_path, l->socket, l->depth + 1);
			chdir("..");
			send(l->socket, "Exit Dir", 8, 0);
			ret = recv(l->socket, l->buff, 1024, 0);
		}
	}
	else
		do_the_sub_thing(l);
	send(l->socket, l->tmp_path[1], l->s->d_namlen, 0);
	free(l->tmp_path[1]);
	ret = recv(l->socket, l->buff, 1024, 0);
	l->buff[ret] = 0;
	return (l->depth);
}

t_deg			*init_deg(char **path, int socket, int depth)
{
	t_deg			*lison;

	if (!(lison = (t_deg*)malloc(sizeof(t_deg))))
		return (NULL);
	lison->tmp_path[0] = ft_strdup(path[0]);
	lison->tmp_path[2] = NULL;
	lison->path = path;
	lison->depth = depth;
	lison->socket = socket;
	return (lison);
}

int				send_dir(char **path, int socket, int depth)
{
	t_deg			*l;
	DIR				*d;
	int				up;

	up = dir_handler(&path[1]);
	l = init_deg(path, socket, depth);
	send(socket, "dir", 3, 0);
	recv(socket, l->buff, 14, 0);
	send(socket, path[1], ft_strlen(path[1]), 0);
	recv(socket, l->buff, 14, 0);
	d = opendir(path[1]);
	chdir(path[1]);
	while ((l->s = readdir(d)))
		l->depth = do_the_thing(l);
	if (l->depth == 1)
	{
		send(socket, "capri", 5, 0);
		chdir("..");
	}
	while (up > 0)
	{
		chdir("..");
		up--;
	}
	return (1);
}

int				s_send(char **path, int socket)
{
	if (!is_dir(path[1]))
		return (send_unique_file(path, socket));
	return (send_dir(path, socket, 1));
}
