/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_ask_ls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 14:16:33 by tlepeche          #+#    #+#             */
/*   Updated: 2015/05/11 17:39:55 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ask_list(char **av, int fd)
{
	pid_t	father;
	int		status;

	father = fork();
	if (father > 0)
		wait4(father, &status, 0, 0);
	if (father == 0)
	{
		dup2(fd, 1);
		if (execv("/bin/ls", av) == -1)
			exit(-1);
	}
	if (WEXITSTATUS(status))
		return (WEXITSTATUS(status) - 1);
	return (1);
}
