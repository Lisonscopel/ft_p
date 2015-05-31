#include "libnetwork.h"

int					is_dir(char *path)
{
	int				is_dir;

	is_dir = 0;
	if (chdir(path) != -1)
	{
		chdir("..");
		is_dir = 1;
	}
	return (is_dir);
}

static int			avada_kedavra(int fd, int socket)
{
	char			buff[1];
	char			tmp[1024];
	char			*size;
	int				ret;
	struct stat		st;

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

int					send_unique_file(char **path, int socket)
{
	char			tmp[1024];
	int				fd;

	if (path[1])
	{
		if ((fd = open(path[1], O_RDONLY)) != -1)
			return (avada_kedavra(fd, socket));
		else
		{
			send(socket, "file", 5, 0);
			recv(socket, tmp, 1024, 0);
			send(socket, "-1", 2, 0);
			recv(socket, tmp, 1024, 0);
			ft_putcolorendl("Pas de fichier", 92);
			return (-1);
		}
	}
	return (0);
}

int					dir_handler(char **path)
{
	char			**t;
	int				t_len;
	int				i;

	t_len = 0;
	i = 0;
	t = ft_strsplit(*path, '/');
	while (t[t_len])
		t_len++;
	t_len -= 1;
	if (t_len == 0)
	{
		free(t);
		return (0);
	}
	while (i < (t_len))
	{
		chdir(t[i]);
		i++;
	}
	*path = ft_strdup(t[t_len]);
	return (t_len);
}
