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

	ft_putendl("\033[0;1mExisting file :\033[0m");
	ft_putstr("(A)bort, (R)ename, (O)verwrite ? ");
	get_next_line(0, &line);
	if (line[0] == 'R')
	{
		ft_putstr("New name : ");
		get_next_line(0, &line);
		close(fd);
		return (create_file(line));
	}
	else if (line[0] == 'O')
	{
		close(fd);
		fd = open(path, O_TRUNC | O_WRONLY);
		return (fd);
	}
	else
		close(fd);
	return (0);
}

int					create_file(char *path)
{
	char			*good_path;
	int				fd;

	good_path = get_path(path);
	if ((fd = open(good_path, O_RDONLY)) != -1)
		return (choose_stuff(good_path, fd));
	else
	{
		fd = open(good_path, O_CREAT | O_WRONLY);
		return (fd);
	}
	return (0);
}

static int			read_file(int socket, int fd, int size)
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

int					receive_dir(char **path, int socket)
{
	char	buff[1024];
	int		ret;
	// struct dirent	*s;

	send(socket, "in receive_dir", 14, 0);
	mkdir(path[1], 0755);
	chdir(path[1]);
	ret = recv(socket, buff, 1023, 0);
	send(socket, "in receive_dir", 14, 0);
	while(42)
	{
		ret = recv(socket, buff, 1023, 0);
		buff[ret] = '\0';
		ft_putcolorendl(buff, 94);
		if (ft_strncmp(buff, "capri", 5) == 0)
			break;
		if (ft_strncmp(buff, "dir", 3) == 0)
		{
			send(socket, "in receive_dir", 14, 0);
			ret = recv(socket, buff, 1023, 0);
			buff[ret] = '\0';
			ft_putcolorendl(buff, 32);
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
				ft_putcolorendl(buff, 31);
				path[1] = ft_strdup(buff);
				send(socket, "go", 2, 0);
				receive_file(path, socket);
			}
			else
				send(socket, "ok", 2, 0);
			// chdir("..");
		}
		else if (ft_strncmp(buff, "Exit Dir", 8) == 0)
		{
			send(socket, "youreout", 8, 0);
			chdir("..");
		}
	}
	chdir("..");
	ft_putcolorendl(" C fini !", 33);
	return (1);
}

int					receive_file(char **path, int socket)
{
	int				ret;
	int				fd;
	char			buff[1024];
	char			*good_path;
	int				size;

	ft_bzero(buff, 1023);
	if ((ret = recv(socket, buff, 1023, 0)) == 0)
		return (0);
	if (!(ft_strcmp(buff, "file") == 0))
	{
		return (receive_dir(path, socket));
	}
	ft_bzero(buff, 1023);
	send(socket, "", 1, 0);
	if ((ret = recv(socket, buff, 1023, 0)) == 0)
		return (0);
	if ((size = ft_atoi(buff)) == 0)
	{
		ft_putendl("SUCCESS");
		return (create_file(path[1]));
	}
	send(socket, "", 1, 0);
	ret = recv(socket, buff, 1023, 0);
	fd = 0;
	if (buff[0] != '\0' && size != 0)
	{
		buff[ret] = '\0';
		good_path = path[1];
		fd = create_file(good_path);
		if (fd <= 0)
			return (read_file(socket, fd, size));
		write(fd, buff, ft_strlen(buff));
		send(socket, "", 1, 0);
	}
	read_file(socket, fd, size);
	if (fd > 0 || size == 0)
	{
		ft_putendl("SUCCESS");
		close(fd);
	}
	else
		ft_putendl("ERROR");
	return (0);
}
