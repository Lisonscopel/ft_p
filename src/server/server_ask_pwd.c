/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_ask_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:06:33 by tlepeche          #+#    #+#             */
/*   Updated: 2015/05/15 18:38:57 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	ask_pwd(char **av, int fd)
{
	char *pwd;

	(void)av;
	pwd = (char *)malloc(sizeof(char) * 1024);
	pwd = getcwd(pwd, 1024);
	ft_putendl(pwd);
	send(fd, pwd, ft_strlen(pwd), 0);
	return (1);
}
