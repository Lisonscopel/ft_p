/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 11:08:17 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/17 20:29:37 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*first(char *str, char *rem, char *rep)
{
	int		j;

	j = 0;
	while (str[j] == rem[j])
		j++;
	if (rem[j] == '\0')
		return (rep);
	else
		return ("");
}

int		tablen(char **tab)
{
	int size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

char	*ft_strreplace(char *s, char *rem, char *rep)
{
	int		i;
	char	**tmp;
	char	*result;
	char	*end;
	int		size;

	tmp = ft_strssplit(s, rem);
	i = 0;
	size = tablen(tmp);
	while (i < size)
	{
		result = (i == 0) ? first(s, rem, rep) : result;
		result = ft_strjoin(result, tmp[i]);
		if (i == size - 1)
		{
			end = ft_strsub(s, ft_strlen(s) - ft_strlen(rem), ft_strlen(s));
			if (ft_strcmp(end, rem) == 0)
				result = ft_strjoin(result, rep);
		}
		else
			result = ft_strjoin(result, rep);
		i++;
	}
	return (result);
}
