#include "libnetwork.h"

static char			*get_path(char *s)
{
	char			*ret;

	if (ft_strchr(s, '/'))
	{
		ret = ft_strrchr(s, '/');
		ret++;
	}
	else
		ret = s;
	return (ret);
}

static int			choose_stuff(char *path, int fd)
{
	char			*line;

	ft_putcolor("Existing file : ", 1);
	ft_putendl("Overwrite");
	get_next_line(0, &line);
	close(fd);
	fd = open(path, O_TRUNC | O_WRONLY);
	return (fd);
}

int					s_create_file(char *path)
{
	char			*good_path;
	int				fd;

	good_path = get_path(path);
	ft_putcolorendl(good_path, 95);
	if ((fd = open(good_path, O_RDONLY)) != -1)
		return (choose_stuff(good_path, fd));
	else
	{
		fd = open(good_path, O_CREAT | O_WRONLY);
		return (fd);
	}
	return (0);
}

int			s_read_file(int socket, int fd, int size)
{
	char			buff[1024];
	int				ret;

	if (fd == 0)
		send(socket, "", 1, 0);
	while (size > 1)
	{
		ret = recv(socket, buff, 1023, 0);
		if (fd > 0)
			write(fd, buff, ret);
		size -= ret;
		send(socket, "", 1, 0);
	}
	return (0);
}

int		s_receive_file(char **path, int socket)
{
	ft_putcolorendl("Server Receive File", 92);

	int				ret;
	int				fd;
	char			buff[1024];
	char			*good_path;
	int				size;

	ft_bzero(buff, 1023);
	if ((ret = recv(socket, buff, 1023, 0)) == 0)
		return (0);

	if (!(ft_strcmp(buff, "file") == 0))
		return (0);

	ft_bzero(buff, 1023);

	send(socket, "", 1, 0);
	
	if ((ret = recv(socket, buff, 1023, 0)) == 0)
		return (0);
	
	if ((size = ft_atoi(buff)) == 0)
	{
		send(socket, "", 1, 0);
		ft_putendl("SUCCESS");
		return (s_create_file(path[1]));
	}
	else if (size == -1)
	{
		ft_putendl("put : File doesn't exist, Dick Head !");
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
		fd = s_create_file(good_path);
		if (fd <= 0)
			return (s_read_file(socket, fd, size));
		write(fd, buff, ft_strlen(buff));
		send(socket, "", 1, 0);
	}
	s_read_file(socket, fd, size);
	if (fd > 0 || size == 0)
	{
		ft_putendl("SUCCESS");
		close(fd);
	}
	else
		ft_putendl("ERROR");

	ft_putcolorendl("End of Server Receive File", 92);
	return (0);	
}