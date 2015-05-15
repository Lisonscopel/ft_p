/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 23:03:19 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/10 15:42:26 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# include "libft.h"
# include "get_next_line.h"
# include "libnetwork.h"

typedef	struct		s_fct
{
	char			*name;
	int				(*ptr_funct)(char **, int);
	struct s_fct	*next;
}					t_fct;

#endif
