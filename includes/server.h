/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 22:56:02 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/11 17:57:46 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include "ft_p.h"

# include <dirent.h>
//# include <fcntl.h>

int					login(void);
void				dial_client(int cs);
void				init(t_fct **list);

int					how_many(char *str, char c);
char				*ft_strnchr(const char *s, int c, int i);

int					ask_cd(char **av, int fd);
int					ask_list(char **av, int fd);
int					ask_pwd(char **av, int fd);
int					ask_get(char **av, int fd);
#endif
