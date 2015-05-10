/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:44:25 by lscopel           #+#    #+#             */
/*   Updated: 2014/11/24 23:46:50 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		lenght;
	char	*s_new;

	s_new = (char *)s;
	lenght = ft_strlen(s);
	while (lenght >= 0)
	{
		if (s_new[lenght] == c)
			return (s_new + lenght);
		lenght--;
	}
	return (NULL);
}
