#include "server.h"

char	*get_root(void)
{
	static char	*root;

	if (!root)
	{
		root = (char *)malloc(sizeof(char) * 1024);
		root = getcwd(root, 1024);
	}
	return (root);
}

int		dir_cmp(char *target, char *root)
{
	int	i;

	i = 0;
	if (ft_strlen(target) < ft_strlen(root))
		return (0);
	else
	{
		while (root[i])
		{
			if (root[i] != target[i])
				return (0);
			i++;
		}
	}
	return (1);
}

int		check_access(char *path)
{
	char	*tmp_path;
	DIR		*dird;
	int		nb;
	int		i;

	nb = how_many(path, '/');
	i = 0;
	while (++i <= nb + 1)
	{
		tmp_path = ft_strnchr(path, '/', i);
		if ((dird = opendir(tmp_path)) == NULL)
			return (0);
		closedir(dird);
	}
	return (1);
}

int		move_dir(char *tar_dir, char *cur_dir, char *root, int fd)
{
	int		len_root;

	len_root = ft_strlen(root);
	chdir(tar_dir);
	tar_dir = getcwd(tar_dir, 1024);
	if (dir_cmp(tar_dir, root) == 0)
	{
		chdir(cur_dir);
		return (put_error(4, fd));
	}
	else
		send(fd, "", 1, 0);
	return (1);
}

int		ask_cd(char **av, int fd)
{
	char	*root;
	char	*cur_dir;
	char	*tar_dir;

	root = get_root();
	cur_dir = (char *)malloc(sizeof(char) * 1024);
	cur_dir = ft_strcat(getcwd(cur_dir, 1024), "/");
	if (av[1])
	{
		if (av[1][0] == '/')
			tar_dir = ft_strjoin(root, av[1]);
		else
			tar_dir = ft_strjoin(cur_dir, av[1]);
	}
	else
		tar_dir = ft_strdup(root);
	if (check_access(tar_dir) == 1)
		return (move_dir(tar_dir, cur_dir, root, fd));
	else
		return (put_error(0, fd));
}
