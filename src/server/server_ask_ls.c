#include "server.h"

static int		check_av(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'A' || str[i] == 'l' || str[i] == 'R')
			i++;
		else
			return (0);
	}
	return (1);
}

static char		*choose_option(char **av)
{
	int		i;
	char	*option;

	i = 1;
	option = ft_strnew(1023);
	option[0] = '-';
	while (av[i])
	{
		if (av[i][0] == '-' && check_av(av[i]) == 1)
			option = ft_strcat(option, av[i] + 1);
		else
			break ;
		i++;
	}
	if (option[1])
		return (option);
	else
		return (NULL);
}

int				ask_list(char **av, int fd)
{
	pid_t		father;
	int			status;
	char		*av_ls[3];

	(void)av;
	av_ls[0] = ft_strdup("ls");
	av_ls[1] = choose_option(av);
	av_ls[2] = NULL;
	father = fork();
	if (father > 0)
		wait4(father, &status, 0, 0);
	if (father == 0)
	{
		dup2(fd, 1);
		if (execv("/bin/ls", av_ls) == -1)
			exit(-1);
	}
	free(av_ls[0]);
	return (1);
}
