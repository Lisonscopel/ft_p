#include "libnetwork.h"

int		client_create_tcp(char *addr, int port)
{
	int					sock;
	struct protoent		*prot;
	struct sockaddr_in	sin;
	struct hostent		*host;
	char				*ip;

	prot = getprotobyname("tcp");
	if ((host = gethostbyname(addr)) == NULL)
	{
		printf("Error: Bad <addr>\n");
		exit (0);
	}
	ip = inet_ntoa(*((struct in_addr *)host->h_addr));
	if (!prot)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, prot->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(ip);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr("Connection error\n");
		exit (2);
	}
	return (sock);
}
