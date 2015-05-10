/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 23:34:42 by lscopel           #+#    #+#             */
/*   Updated: 2015/03/19 11:43:57 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int					count_lines(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] && str[i] != '\n')
		i++;
	if (i == ft_strlen(str))
		return (0);
	return (1);
}

char				*makeline(char *str)
{
	int				i;
	char			*new;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	new = ft_strnew(i + 1);
	new = ft_strncpy(new, str, i);
	return (new);
}

int					reader(int fd, char **stock)
{
	char			*ostock;
	char			*s1;
	int				ret;

	s1 = ft_strnew(BUFF_SIZE + 1);
	while (count_lines(*stock) != 1 && (ret = read(fd, s1, BUFF_SIZE)) > 0)
	{
		ostock = *stock;
		*stock = ft_strjoin(*stock, s1);
		free(ostock);
		ft_bzero(s1, BUFF_SIZE + 1);
	}
	return (ret);
}

int					get_next_line(int fd, char **line)
{
	int				ret;
	static char		*stock = NULL;
	char			*ostock;
	int				ll;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!stock)
		stock = ft_strnew(BUFF_SIZE + 1);
	ret = reader(fd, &stock);
	if (ret < 0)
		return (-1);
	if (ret == 0 && ft_strlen(stock) == 0)
	{
		(void)ostock;
		ft_strdel(&stock);
		*line = ft_strnew(2);
		return (0);
	}
	*line = makeline(stock);
	ll = ft_strlen(*line);
	stock = ft_strsub(stock, (ll + 1), (ft_strlen(stock) - ll - 1));
	return (1);
}
