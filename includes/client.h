#ifndef CLIENT_H
# define CLIENT_H
# include "ft_p.h"

int		how_many(char *str, char c);
void	dial_server(int sock, char *line);
void	init(t_fct **list);
int		ask_get(char **new_av, int sock);
int		ask_quit(char **new_av, int sock);
int		ask_put(char **path, int socket);
int		client_login(int sock, char **login);

#endif
