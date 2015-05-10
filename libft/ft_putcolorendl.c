/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolorendl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:05:26 by ghilbert          #+#    #+#             */
/*   Updated: 2015/03/23 17:05:27 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putcolorendl(char *str, int color)
{
	ft_putcolor(str, color);
	ft_putchar('\n');
}
