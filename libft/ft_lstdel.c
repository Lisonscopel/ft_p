/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 14:44:28 by lscopel           #+#    #+#             */
/*   Updated: 2015/01/02 20:28:15 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next_lst;

	if (alst == NULL || del == NULL)
		return ;
	if (*alst)
	{
		tmp = *alst;
		while (tmp != NULL)
		{
			next_lst = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = next_lst;
		}
		*alst = NULL;
	}
}
