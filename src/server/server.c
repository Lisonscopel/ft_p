#include "server.h"

void					close_exit(int socket)
{
	close(socket);
	exit(0);
}

int						main(int ac, char **av)
{
	int					port;
	int					sock;
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;

	if (ac != 2)
		ft_usage(av[0], " <port>");
	port = ft_atoi(av[1]);
	sock = serv_create_tcp(port);
	while (42)
	{
		cs = accept(sock, (struct sockaddr *)&csin, &cslen);
		if (fork() == 0)
		{
			if ((server_login(cs)) == -1)
			{
				close(cs);
				close_exit(sock);
			}
			dial_client(cs);
			close_exit(cs);
		}
	}
	close_exit(sock);
}
