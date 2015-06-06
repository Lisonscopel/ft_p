/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libnetwork.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:03:18 by lscopel           #+#    #+#             */
/*   Updated: 2015/06/06 13:15:23 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNETWORK_H
# define LIBNETWORK_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/dir.h>

# include "libft.h"

typedef struct		s_deg
{
	struct dirent	*s;
	char			*tmp_path[3];
	char			*buff[1024];
	char			**path;
	int				depth;
	int				socket;
}					t_deg;

/*
**server
*/
int					serv_create_tcp(int port);
int					s_send(char **path, int socket);
int					s_receive_file(char **path, int socket);
int					c_create_file(char *path);
int					send_dir(char **path, int socket, int depth);
int					is_dir(char *path);
int					send_unique_file(char **path, int socket);
int					dir_handler(char **path);

/*
**client
*/
int					client_create_tcp(char *addr, int port);
int					c_receive_file(char **path, int socket);
int					c_create_file(char *path);
int					c_read_file(int socket, int fd, int size);
int					c_send(char **path, int socket);

/*
**both
*/
int					report(int err, int socket);

#endif
