/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dial_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:03:41 by lscopel           #+#    #+#             */
/*   Updated: 2015/06/06 13:34:24 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		byte_reception(char **new_av, char *buf, int ret)
{
	ft_putstr("received ");
	ft_putnbr(ret);
	ft_putstr(" bytes: ");
	ft_putendl(buf);
	ft_free_tab(new_av);
}

int			display_prompt(char **new_av, int sock)
{
	char	*pwd;

	(void)new_av;
	pwd = ft_strjoin(pwd_handler(), " > ");
	send(sock, pwd, ft_strlen(pwd), 0);
	return (1);
}

static int	cmd_handler(t_fct *tmp, char *buf, char ***new_av, int cs)
{
	int		bool;

	*new_av = ft_strsplit_blank(buf);
	bool = 0;
	while (tmp != NULL)
	{
		if (*new_av[0] && ft_strcmp(tmp->name, *new_av[0]) == 0)
		{
			bool = 1;
			tmp->ptr_funct(*new_av, cs);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void		dial_client(int cs)
{
	int		ret;
	char	**new_av;
	char	buf[1024];
	t_fct	*list;
	t_fct	*tmp;

	init(&list);
	tmp = list;
	while ((ret = recv(cs, buf, 1023, 0)) > 0)
	{
		buf[ret] = '\0';
		if (cmd_handler(tmp, buf, &new_av, cs) == 0)
			server_report(3, cs);
		byte_reception(new_av, buf, ret);
	}
}
