/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:13:29 by lscopel           #+#    #+#             */
/*   Updated: 2014/11/24 23:24:42 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter(int n)
{
	int		i;

	i = 1;
	while (n < 0 || n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		is_neg;

	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n = n * -1;
	}
	i = counter(n);
	str = ft_strnew(i + is_neg + 1);
	if (n == -2147483648)
		return ("-2147483648");
	if (is_neg == 1)
		str[0] = '-';
	if (str == NULL)
		return (NULL);
	while (i)
	{
		str[--i + is_neg] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
