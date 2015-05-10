/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:13:56 by lscopel           #+#    #+#             */
/*   Updated: 2014/12/13 23:14:06 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*strnew;
	int		i;

	i = 0;
	strnew = (char *)malloc(sizeof(char) * len + 1);
	if (strnew == NULL || start + len > ft_strlen((char *)s))
		return (NULL);
	if (strnew == NULL || (int)len < 0)
		return (NULL);
	while (len && s[start])
	{
		strnew[i] = s[start];
		start++;
		len--;
		i++;
	}
	strnew[i] = '\0';
	return (strnew);
}
