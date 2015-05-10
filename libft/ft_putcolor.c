/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:05:00 by ghilbert          #+#    #+#             */
/*   Updated: 2015/03/23 17:05:16 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putcolor(char *str, int color)
{
	ft_putstr("\033[");
	ft_putnbr(color);
	ft_putstr("m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}
