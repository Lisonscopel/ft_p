/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_ask_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 15:06:33 by tlepeche          #+#    #+#             */
/*   Updated: 2015/05/11 17:54:30 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	ask_pwd(char **av, int fd)
{
	char *pwd;

	(void)av;
	pwd = (char *)malloc(sizeof(char) * 1024);
	pwd = getcwd(pwd, 1024);
	send(fd, pwd, ft_strlen(pwd), 0);
	return (1);
}
