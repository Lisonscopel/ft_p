#include "client.h"

int		client_login(int sock, char **login)
{
	char	buff[1024];
	char	*line;
	char	*line2;
	int		i;

	send(sock, "okcbon", 7, 0);
	ft_putendl("Login:");
	if ((i = get_next_line(0, &line)) == 0)
		exit(0);
	*login = ft_strdup(line);
	ft_putendl("Password:");
	if ((i = get_next_line(0, &line2)) == 0)
		exit(0);
	line = ft_strjoin(line, ":");
	line = ft_strjoin(line, line2);
	recv(sock, buff, 1023, 0);
	send(sock, line, ft_strlen(line) + 1, 0);
	recv(sock, buff, 1023, 0);
	if (!(ft_strcmp(buff, "shameonyou")))
	{
		ft_putendl("Wrong Password you jerk");
		return (-1);
	}
	printf("Welcome %s !\n", *login);
	return (0);
}
