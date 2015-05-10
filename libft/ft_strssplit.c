/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strssplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 11:11:34 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/17 19:17:16 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		test(char *str, char *tmp, char *p, int result)
{
	while (tmp)
	{
		tmp = ft_strstr(str, p);
		if (tmp == NULL)
		{
			tmp = 0;
			result++;
		}
		else
		{
			if (ft_strcmp(tmp, str) == 0)
			{
				tmp = ft_strsub(str, ft_strlen(p), ft_strlen(str));
				str = tmp;
			}
			else
				result++;
			if (ft_strcmp(tmp, p) == 0)
				tmp = 0;
			if (tmp)
				str = tmp;
		}
	}
	return (result);
}

static	int		ft_wordnb(char *str, char *p)
{
	int		i;
	int		j;
	int		result;
	char	*tmp;

	if (ft_strlen(str) < ft_strlen(p) || ft_strcmp(str, p) == 0)
		return (0);
	i = 0;
	j = 0;
	tmp = str;
	result = test((char *)str, tmp, p, 0);
	return (result);
}

static char		*sub(char *str, char **tmp, char *p)
{
	*tmp = ft_strsub(str, ft_strlen(p), ft_strlen(str));
	return (*tmp);
}

static char		**split_words(char *str, char *p, int words)
{
	int		k;
	char	**sp;
	char	*tmp;

	sp = (char **)malloc(sizeof(char *) * words + 1);
	k = 0;
	tmp = str;
	while (tmp)
	{
		tmp = ft_strstr(str, p);
		if (tmp == NULL)
			sp[k++] = str;
		else
		{
			if (ft_strcmp(tmp, str) == 0)
				str = sub(str, &tmp, p);
			else
				sp[k++] = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(tmp));
			tmp = (ft_strcmp(tmp, p) == 0) ? 0 : tmp;
			str = tmp ? tmp : str;
		}
	}
	sp[k] = 0;
	return (sp);
}

char			**ft_strssplit(char const *s, char *pattern)
{
	char	**splits;
	int		i;
	int		j;
	int		k;
	int		words;

	if (!s)
		return (NULL);
	if (!pattern)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	words = ft_wordnb((char *)s, pattern);
	splits = split_words((char *)s, pattern, words);
	return (splits);
}
