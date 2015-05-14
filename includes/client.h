/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 22:56:02 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/11 21:10:49 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include "ft_p.h"

int		how_many(char *str, char c);
void	dial_server(int sock, char *line);
void	init(t_fct **list);
int		ask_get(char **new_av, int sock);
int		ask_quit(char **new_av, int sock);

#endif
