#ifndef SERVER_H
# define SERVER_H
# include "ft_p.h"

# include <dirent.h>
# include <sys/stat.h>

void	dial_client(int cs);
void	init(t_fct **list);

int		how_many(char *str, char c);
char	*ft_strnchr(const char *s, int c, int i);

int		ask_cd(char **av, int fd);
int		ask_list(char **av, int fd);
int		ask_pwd(char **av, int fd);
char	*pwd_handler(void);
int		ask_get(char **av, int fd);
char	*get_root(void);
int		display_prompt(char **new_av, int sock);
int		server_login(int sock);
int		lls(char **path, int socket);
int		lpwd(char **path, int socket);
int		lcd(char **path, int socket);

/*
 * PUT
 */
int		put_create_file(char *path, int socket);
int		ask_put(char** path, int socket);

#endif
