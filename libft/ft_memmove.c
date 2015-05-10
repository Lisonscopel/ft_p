/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 18:10:24 by lscopel           #+#    #+#             */
/*   Updated: 2014/11/24 23:40:17 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (!(dst))
		return (dst);
	if (!(src))
		return (dst);
	s = (const char *)src;
	d = (char *)dst;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	s += len;
	d += len;
	while (len)
	{
		len--;
		*--d = *--s;
	}
	return (dst);
}
