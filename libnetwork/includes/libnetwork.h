/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libnetwork.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 14:15:19 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/30 21:10:52 by ghilbert         ###   ########.fr       */
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
int		c_send(char **path, int socket);
int		c_create_file(char *path);

/*
**both
*/

#endif
