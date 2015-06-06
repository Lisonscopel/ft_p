/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:03:18 by lscopel           #+#    #+#             */
/*   Updated: 2015/06/06 13:12:16 by lscopel          ###   ########.fr       */
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
