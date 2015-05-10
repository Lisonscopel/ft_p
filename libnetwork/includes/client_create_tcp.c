#include "libnetwork.h"

int		client_create_tcp(char *addr, int port)
{
	int					sock;
	struct protoent		*prot;
	struct sockaddr_in	sin;

	prot = getprotobyname("tcp");
	if (!prot)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, prot->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr("Connection error\n");
		exit (2);
	}
	return (sock);
}