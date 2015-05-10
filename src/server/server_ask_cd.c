/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_ask_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 19:55:57 by tlepeche          #+#    #+#             */
/*   Updated: 2015/05/10 22:05:31 by tlepeche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return(0);
	else
	{
		while(root[i])
		{
			if (root[i] != target[i])
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_acess(char *path)
{
	char	*tmp_path;
	int		nb;
	int		i;

	nb = how_many(path, '/');

}

void	ask_cd(char **av, int fd)
{
	char	*root;
	char	*cur_dir;
	char	*tar_dir;

	if (ft_strcmp(av[0], "cd") != 0)
		return (-1);
	else
	{
		root = get_root();
		cur_dir =  (char *)malloc(sizeof(char) * 1024);
		cur_dir = getcwd(dir, 1024);
		if (av[1])
			tar_dir = ft_strjoin(cur_dir, av[1]);
		else
			tar_dir = ft_strdup(root);
		if (check_access(tar_dir) == 1) //verfiration du path donné;
		{
			chdir(tar_dir);
			tar_dir = getcwd(tar_dir, 1024);
			if (dir_cmp(tar_dir, root) == 1) //check si on est au dessus du root;
			{
				chdir(cur_dir);
				return (0);
			}
			else
				return (1);
		}
		else
			return (0);
	}
}
