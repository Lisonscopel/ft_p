/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:03:18 by lscopel           #+#    #+#             */
/*   Updated: 2015/06/06 13:15:57 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		ask_quit(char **new_av, int sock)
{
	(void)new_av;
	(void)sock;
	ft_putendl("SUCCESS");
	exit (0);
	return (-1);
}
