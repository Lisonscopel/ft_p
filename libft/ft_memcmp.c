/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 18:28:10 by lscopel           #+#    #+#             */
/*   Updated: 2014/11/24 20:13:27 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s;
	unsigned char	*c;
	unsigned int	i;

	if (n == 0)
		return (0);
	c = (unsigned char *)s1;
	s = (unsigned char *)s2;
	if (!s || !c)
		return (0);
	i = 0;
	while (i < n)
	{
		if (c[i] != s[i])
			return (c[i] - s[i]);
		i++;
	}
	return (0);
}
