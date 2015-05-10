/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libnetwork.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 14:15:19 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/10 14:15:41 by lscopel          ###   ########.fr       */
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

int		serv_create_tcp(int port);


#endif
