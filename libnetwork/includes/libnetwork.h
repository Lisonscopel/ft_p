/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libnetwork.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 14:15:19 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/10 15:22:48 by ghilbert         ###   ########.fr       */
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

# include "libft.h"

/*
**server
*/
int		serv_create_tcp(int port);
 
/*
**client
*/
int		client_create_tcp(char *addr, int port);

/*
**both
*/


#endif
