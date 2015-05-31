/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libnetwork.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 14:15:19 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/30 23:09:11 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIBNETWORK_H
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
#include <sys/types.h>
#include <sys/dir.h>

# include "libft.h"

/*
**server
*/
int		serv_create_tcp(int port);
int		s_send(char **path, int socket);
int		s_receive_file(char **path, int socket);
int		c_create_file(char *path);

/*
**client
*/
int		client_create_tcp(char *addr, int port);
int		c_receive_file(char **path, int socket);
int		c_create_file(char *path);
int		c_read_file(int socket, int fd, int size);
int		c_send(char **path, int socket);

/*
**both
*/
int		report(int err, int socket);

#endif
