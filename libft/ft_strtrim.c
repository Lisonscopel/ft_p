/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:03:18 by lscopel           #+#    #+#             */
/*   Updated: 2015/06/06 13:14:36 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		count_space_before(char *s)
{
	unsigned int		i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	return (i);
}

static size_t			count_space_after(char *s)
{
	int					j;
	int					k;

	k = 0;
	j = ft_strlen(s) - 1;
	if (j < 1)
		return (0);
	while (s[j] && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
	{
		k++;
		j--;
	}
	return (k);
}

char					*ft_strtrim(char const *s)
{
	unsigned int		start;
	size_t				len;
	char				*new;
	char				*s_cpy;

	if (!s)
		return (NULL);
	s_cpy = ft_strdup(s);
	start = count_space_before(s_cpy);
	if (count_space_after(s_cpy) == 0 && start == 0)
		return (s_cpy);
	if (start == ft_strlen(s))
		return ("");
	len = (ft_strlen(s_cpy)) - ((count_space_after(s_cpy)) + start);
	new = ft_strsub(s, start, len);
	ft_strdel(&s_cpy);
	return (new);
}
