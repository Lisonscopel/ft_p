#include "server.h"

int	ask_list(char **new_av, int cs)
{
	pid_t	father;

	father = fork();
 	if (father > 0)
			wait4(father, 0, 0, 0);
	if (father == 0)
	{
		dup2(cs, 1);
		if (execv("/bin/ls", new_av) == -1)
			exit(0);
	}
	return (0);
}

int	ask_bonjour(char **new_av, int cs)
{
	(void)new_av;
	send(cs, "Salut", ft_strlen("salut"), 0);
	return (0);
}

int	ask_pwd(char **new_av, int cs)
{
	char	*pwd;

	(void)new_av;
	if ((pwd = (char *)malloc(sizeof(char) * 1024)) == NULL)
		return (-1);
	pwd = getcwd(pwd, 1024);
	send(cs, pwd, ft_strlen(pwd), 0);
	return (0);
}

int	ask_quit(char **new_av, int cs)
{
	(void)new_av;
	close(cs);
	return (0);
}
