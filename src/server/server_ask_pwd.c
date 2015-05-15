#include "server.h"

int	ask_pwd(char **av, int fd)
{
	char	*pwd;
	char	*root;
	int		len_root;
	int		len;
	char	*dir;

	(void)av;
	pwd = (char *)malloc(sizeof(char) * 1024);
	pwd = getcwd(pwd, 1024);
	root = get_root();
	len_root = ft_strlen(root) + 1;
	len = ft_strlen(pwd);
	len = len - len_root;
	dir = ft_strsub(pwd, len_root, len);
	if (!dir)
		send(fd, "/", 1, 0);
	else
	{
		dir = ft_strjoin("/", dir);
		send(fd, dir, ft_strlen(dir), 0);
	}
	return (1);
}
