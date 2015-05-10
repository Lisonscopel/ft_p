/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 22:56:02 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/10 02:01:37 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include "ft_p.h"

typedef	struct		s_fct
{
	char			*name;
	void			(*ptr_funct)(char **, int);
	struct s_fct	*next;
}					t_fct;

int					login(void);
void				dial_client(int cs);

#endif
