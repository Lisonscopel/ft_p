/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpailhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 22:40:04 by vpailhe           #+#    #+#             */
/*   Updated: 2015/05/10 02:04:14 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char		*ask(char *s)
{
	char	pass[1024];
	char	*rtn;

	ft_bzero(pass, 1023);
	ft_putstr(s);
	scanf("%49s", pass);
	rtn = ft_strdup(pass);
	return (rtn);
}

int			equal_find(char *s)
{
	size_t		i;

	i = 0;
	while(s[i] != '=' && s[i])
		i++;
	if (i == ft_strlen(s))
		return (-1);
	return (i);
}

char		*parse_me(char *s)
{
	int		i;

	i = 0;
	while(s[i] != '=' && s[i])
		i++;
	s += i + 1;
	return (s);
}

int			password(char *line)
{
	char	*ans;
	char	*mdp;

	ans = ask("Password :");
	mdp = parse_me(line);
	if (!ft_strcmp(ans, mdp))
		return (1);
	ft_putendl("\033[031mWRONG PASSWORD \033[0m");
	return (0);
}

int			login(void)
{
	int		fd;
	int		rd;
	int		eq;
	char	*line;
	char	*ans;

	ans = ask("Login :");
	if (!(fd = open("log", O_RDONLY)))
		return (-1);
	while((rd = get_next_line(fd, &line)) > 0)
	{
		eq = equal_find(line);
		if (!(strncmp(ans, line, eq)))
		{
			if (password(line))
				return (1);
			close(fd);
			return (0);
		}
	}
	ft_putendl("\033[031mWRONG LOGIN \033[0m");
	close(fd);
	return (0);
}

/*int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
	if (login() == 1)
		return (1);
	else
		return (0);
}*/
