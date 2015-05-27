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

int					send_unique_file(char **path, int socket)
{
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
			if (st.st_size == 0)
			{
				send(socket, "0", 2, 0);
				return (0);
			}
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
	}
	return (0);
}


int					send_dir(char **path, int socket, int depth)
{
	DIR				*d;
	struct dirent	*s;
	char			*tmp_path[3];
	char			buff[1024];
	int				ret;

	ft_putcolorendl(path[1], 35);
	send(socket, "dir", 3, 0);
	recv(socket, buff, 14, 0);
	send(socket, path[1], ft_strlen(path[1]), 0);
	recv(socket, buff, 14, 0);
	d = opendir(path[1]);
	ret = chdir(path[1]);
	tmp_path[0] = ft_strdup(path[0]);
	tmp_path[2] = NULL;
	while ((s = readdir(d)))
	{
		tmp_path[1] = ft_strdup(s->d_name);
		if ((ret = chdir(tmp_path[1]) != -1) )
		{
			if (ft_strcmp(tmp_path[1], "..") == 0)
			{
				ret = chdir(path[1]);
			}
			else if (ft_strcmp(tmp_path[1], ".") != 0)
			{
				chdir("..");
				send_dir(tmp_path, socket, depth + 1);
				chdir("..");
				send(socket, "Exit Dir", 8, 0);
				ret = recv(socket, buff, 1024, 0);
			}
		}
		else
		{
			send(socket, "getready", 8, 0);
			ret = recv(socket, buff, 1024, 0);
			buff[ret] = '\0';
			send(socket, tmp_path[1], ft_strlen(tmp_path[1]), 0);
			ret = recv(socket, buff, 2, 0);
			send_unique_file(tmp_path, socket);
			ft_putcolorendl(tmp_path[1], 94);
		}
		send(socket, tmp_path[1], s->d_namlen, 0);
		free(tmp_path[1]);
		ret = recv(socket, buff, 1024, 0);
		buff[ret] = '\0';
		ft_putcolorendl(buff, 33);
	}
	if (depth == 1)
	{
		send(socket, "capri", 5, 0);
		chdir("..");
	}
	return (1);
}

int					send_file(char **path, int socket)
{
	if (!is_dir(path[1]))
		return (send_unique_file(path, socket));
	else
		return (send_dir(path, socket, 1));
	return (0);
}
