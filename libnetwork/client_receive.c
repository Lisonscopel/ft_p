#include "libnetwork.h"

int					c_receive_dir(char **path, int socket)
{
	char	buff[1024];
	int		ret;

	send(socket, "in receive_dir", 14, 0);
	path[1] = get_path(path[1]);
	mkdir(path[1], 0755);
	chdir(path[1]);
	ret = recv(socket, buff, 1023, 0);
	send(socket, "in receive_dir", 14, 0);
	while (42)
	{
		ret = recv(socket, buff, 1023, 0);
		buff[ret] = '\0';
		if (ft_strncmp(buff, "capri", 5) == 0)
			break ;
		if (ft_strncmp(buff, "dir", 3) == 0)
		{
			send(socket, "in receive_dir", 14, 0);
			ret = recv(socket, buff, 1023, 0);
			buff[ret] = '\0';
			mkdir(buff, 0755);
			chdir(buff);
			send(socket, "ok", 2, 0);
		}
		else if (ft_strncmp(buff, "Exit Dir", 8) != 0)
		{
			if (ft_strncmp(buff, "getready", 8) == 0)
			{
				send(socket, "ready", 5, 0);
				ret = recv(socket, buff, 1023, 0);
				buff[ret] = '\0';
				ft_putendl(buff);
				path[1] = ft_strdup(buff);
				send(socket, "go", 2, 0);
				c_receive_file(path, socket);
			}
			else
				send(socket, "ok", 2, 0);
		}
		else if (ft_strncmp(buff, "Exit Dir", 8) == 0)
		{
			send(socket, "youreout", 8, 0);
			chdir("..");
		}
	}
	chdir("..");
	return (1);
}

int					c_receive_file(char **path, int socket)
{
	int				ret;
	int				fd;
	char			buff[1024];
	char			*good_path;
	int				size;

	ft_bzero(buff, 1023);
	if ((ret = recv(socket, buff, 1023, 0)) == 0)
		return (-1);
	if (!(ft_strcmp(buff, "file") == 0))
	{
		return (c_receive_dir(path, socket));
	}
	ft_bzero(buff, 1023);
	send(socket, "", 1, 0);
	if ((ret = recv(socket, buff, 1023, 0)) == 0)
		return (-1);
	if ((size = ft_atoi(buff)) == 0)
	{
		send(socket, "", 1, 0);
		return (c_create_file(path[1]));
	}
	else if (size == -1)
	{
		ft_putendl("get : File doesn't exist, Dick Head !");
		send(socket, "", 1, 0);
		return (-1);
	}
	send(socket, "", 1, 0);
	ret = recv(socket, buff, 1023, 0);
	fd = 0;
	if (buff[0] != '\0' && size != 0)
	{
		buff[ret] = '\0';
		good_path = path[1];
		fd = c_create_file(good_path);
		if (fd <= 0)
			return (c_read_file(socket, fd, size));
		write(fd, buff, ft_strlen(buff));
		send(socket, "", 1, 0);
	}
	c_read_file(socket, fd, size);
	if (fd > 0 || size == 0)
	{
		close(fd);
		return (0);
	}
	else
		return (-1);
}
