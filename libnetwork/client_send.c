#include "libnetwork.h"

int	c_send(char **path, int socket)
{
	ft_putcolorendl("Client Send File", 92);

	char			buff[1];
	char			tmp[1024];
	int				fd;
	int				ret;
	struct stat		st;
	char			*size;

	if (path[1])
	{
		if ((fd = open(path[1], O_RDONLY)) != -1)
		{
			fstat(fd, &st);
			size = ft_itoa(st.st_size);
			send(socket, "file", 5, 0);
			recv(socket, tmp, 1024, 0);
			send(socket, size, ft_strlen(size), 0);
			recv(socket, tmp, 1024, 0);
			while ((ret = read(fd, buff, 1)) > 0)
			{
				send(socket, buff, ret, 0);
				recv(socket, tmp, 1024, 0);
			}
			close(fd);
			return (1);
		}
		else
		{
			send(socket, "file", 5, 0);
			recv(socket, tmp, 1024, 0);
			send(socket, "-1", 2, 0);
			recv(socket, tmp, 1024, 0);
			ft_putcolorendl("Pas de fichier", 31);
			return (-1);
		}
	}

	ft_putcolorendl("End Of Client Send File", 92);
	return (0);
}
