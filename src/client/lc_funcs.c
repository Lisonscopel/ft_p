/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:03:18 by lscopel           #+#    #+#             */
/*   Updated: 2015/06/06 13:16:12 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			lcd(char **path, int socket)
{
	(void)socket;
	if (path[1] && chdir(path[1]) == -1)
	{
		ft_putendl("ERROR");
		return (0);
	}
	ft_putendl("SUCCESS");
	return (1);
}

int			lpwd(char **path, int socket)
{
	char	*pwd;

	(void)path;
	(void)socket;
	pwd = ft_strnew(1024);
	if (!getcwd(pwd, 1023))
	{
		ft_putendl("ERROR");
		return (0);
	}
	ft_putendl(pwd);
	return (1);
}

int			lls(char **av, int fd)
{
	pid_t	father;
	int		status;
	char	*av_ls[3];

	(void)fd;
	av_ls[0] = ft_strdup("ls");
	av_ls[1] = av[1];
	av_ls[2] = NULL;
	father = fork();
	if (father > 0)
		wait4(father, &status, 0, 0);
	if (father == 0)
	{
		if (execv("/bin/ls", av_ls) == -1)
			exit(-1);
	}
	free(av_ls[0]);
	return (1);
}
