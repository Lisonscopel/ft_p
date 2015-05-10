/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 07:08:49 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/12 08:42:35 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int n, int p)
{
	unsigned int	i;
	int				res;
	int				negpow;
	unsigned int	pospow;

	res = n;
	negpow = 0;
	if (p == 0)
		return (1);
	else if (p < 0)
	{
		pospow = -p;
		negpow = 1;
	}
	else
		pospow = p;
	i = 1;
	while (i < pospow)
	{
		res *= n;
		i++;
	}
	if (negpow)
		res = 1 / res;
	return (res);
}
