/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <lscopel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 13:03:18 by lscopel           #+#    #+#             */
/*   Updated: 2015/06/06 13:10:36 by lscopel          ###   ########.fr       */
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
