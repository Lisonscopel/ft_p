/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 03:24:23 by tlepeche          #+#    #+#             */
/*   Updated: 2015/05/11 19:48:58 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		create_line(char **temp, char *buf, char *rmning)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(*temp);
	temp[0] = ft_realloc(*temp, (ft_strlen(*temp) + ft_strlen(buf) + 1));
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			*((*temp) + j) = '\0';
			rmning = ft_strcpy(rmning, &buf[++i]);
			return (1);
		}
		temp[0][j++] = buf[i++];
	}
	ft_bzero(rmning, ft_strlen(rmning));
	*((*temp) + j) = '\0';
	return (0);
}

static void		free_mem(char **buf, char **templine)
{
	free(*buf);
	*buf = NULL;
	free(*templine);
	*templine = NULL;
}

static int		ending_file(char **line, char **templine, char **buf)
{
	*line = ft_strdup(*templine);
	free_mem(buf, templine);
	if (line[0] == '\0')
		return (0);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char		rmning[BUFF_SIZE];
	int				ret;
	char			*buf;
	char			*templine;

	if (fd == -1)
		return (-1);
	buf = ft_memalloc(BUFF_SIZE + 1);
	templine = ft_memalloc(BUFF_SIZE + 1);
	if (!templine || !buf)
		return (-1);
	if (create_line(&templine, rmning, rmning) == 1)
		return (ending_file(line, &templine, &buf));
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (create_line(&templine, buf, rmning) == 1)
			return (ending_file(line, &templine, &buf));
	}
	if (ret == -1)
		return (-1);
	if (ret == 0 && templine[0] != '\0')
		return (ending_file(line, &templine, &buf));
	free_mem(&buf, &templine);
	return (0);
}
