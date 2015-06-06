/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:03:18 by lscopel           #+#    #+#             */
/*   Updated: 2015/06/06 13:13:00 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;

	if (!ptr)
		return (ft_memalloc(size));
	if (!size)
		return (ptr);
	if (!(ret = ft_memalloc(size)))
		return (ptr);
	ft_memcpy(ret, ptr, size);
	free(ptr);
	ptr = NULL;
	return (ret);
}
