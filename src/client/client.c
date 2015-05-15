#include "client.h"

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
	while (42)
	{
		ft_putstr("client> ");
		if ((ret = get_next_line(0, &line)) <= 0)
			ft_putcolorendl("ERROR", 91);
		else if (line[0] != '\0')
			dial_server(sock, line);
		free(line);
	}
	close(sock);
	return (0);
}
