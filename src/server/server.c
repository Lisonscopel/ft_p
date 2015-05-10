/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/09 17:22:10 by sduprey           #+#    #+#             */
/*   Updated: 2015/05/10 02:05:08 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h" 

void	usage(char *str)
{
	printf("usage: %s <port>\n", str);
	exit(-1);
}

int		create_server(int port)
{
	int 			sock;
	struct protoent	*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Bind error\n");
		exit(2);
	}
	listen(sock, 42);
	return (sock);
}

int		main(int ac, char **av)
{
	int					port;
	int					sock;
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	int					r;
	char				buf[1024];

	if (ac != 2)
		usage(av[0]);
	port = atoi(av[1]);
	sock = create_server(port);
	cs = accept(sock, (struct sockaddr *)&csin, &cslen);
	while ((r = read(cs, buf, 1023)) > 0)
	{
		buf[r] = '\0';
		if (login() == 1)
			return (-1);
		printf("received %d bytes: %s\n", r, buf);
	}
	close(cs);
	close(sock);
	return (0);
}
