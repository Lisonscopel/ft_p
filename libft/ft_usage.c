/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 14:08:52 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/10 14:11:04 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_usage(char *prog_name, char *args)
{
	ft_putstr("Usage: ");
	ft_putstr(prog_name);
	ft_putendl(args);
	exit (-1);
}
