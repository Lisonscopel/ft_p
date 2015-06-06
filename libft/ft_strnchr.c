/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:03:18 by lscopel           #+#    #+#             */
/*   Updated: 2015/06/06 13:13:50 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, int i)
{
	int		a;
	int		j;
	char	conv;
	char	*s2;

	if (!s || i < 0)
		return (NULL);
	conv = (char)c;
	a = 0;
	j = 0;
	s2 = ft_strdup(s);
	while (s2[a])
	{
		if (s2[a] == conv)
			j++;
		if (j == i)
		{
			s2[a + 1] = '\0';
			break ;
		}
		a++;
	}
	return (s2);
}
