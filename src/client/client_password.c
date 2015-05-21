#include "client.h"

int		client_login(int sock)
{
	char	buff[1024];
	char	*line;
	char	*line2;
	char	*name;

	send(sock, "okcbon", 7, 0);
	ft_putendl("Login:");
	get_next_line(0, &line);
	name = ft_strdup(line);
	ft_putendl("Password:");
	get_next_line(0, &line2);
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
	ft_putstr("Welcome ");
	ft_putcolor(name, 1);
	ft_putendl(" !");
	return (0);
}