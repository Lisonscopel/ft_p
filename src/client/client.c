#include "client.h"

int		login(int sock)
{
	char	buff[1024];
	char	*line;
	char	*line2;

	ft_putendl("yo");

	send(sock, "okcbon", 6, 0);

	ft_putendl("Login:");
	get_next_line(0, &line);
	ft_putendl("Password:");
	get_next_line(0, &line2);
	line = ft_strjoin(line, ":");
	line = ft_strjoin(line, line2);

	recv(sock, buff, 1023, 0);

	send(sock, line, ft_strlen(line), 0);

	ft_putendl(line);
	return (0);
}

static void	prompt(int sock)
{
	char	buff[1024];
	int		ret;

	ret = 0;
	send(sock, "affiche_mon_prompt_steuple_thx_bye", 35, 0);
	if ((ret = recv(sock, buff, 1023, 0)) <= 0)
	{
		ft_putstr("Connection Error\n");
		exit(0);
	}
	buff[ret] = '\0';
	ft_putstr(buff);
}

int			main(int ac, char **av)
{
	int		ret;
	char	*line;
	int		port;
	int		sock;

	if (ac != 3)
		ft_usage(av[0], " <addr> <port>");
	port = ft_atoi(av[2]);
	sock = client_create_tcp(av[1], port);
	if (login(sock))
		return (0);
	while (42)
	{
		prompt(sock);
		if ((ret = get_next_line(0, &line)) <= 0)
			ft_putcolorendl("ERROR", 94);
		else if (line[0] != '\0')
			dial_server(sock, line);
		free(line);
	}
	close(sock);
	return (0);
}
