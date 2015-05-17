#include "server.h"

char		*pwd_handler(void)
{
	char	*pwd;
	char	*root;
	int		len_root;
	int		len;
	char	*dir;

	pwd = (char *)malloc(sizeof(char) * 1024);
	pwd = getcwd(pwd, 1024);
	root = get_root();
	len_root = ft_strlen(root) + 1;
	len = ft_strlen(pwd);
	len = len - len_root;
	dir = ft_strsub(pwd, len_root, len);
	if (!dir)
		return ("/");
	else
		return (ft_strjoin("/", dir));
}

int			ask_pwd(char **av, int fd)
{
	char	*pwd;

	(void)av;
	pwd = pwd_handler();
	send(fd, pwd, ft_strlen(pwd), 0);
	return (1);
}
