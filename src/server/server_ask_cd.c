/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_ask_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlepeche <tlepeche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 19:55:57 by tlepeche          #+#    #+#             */
/*   Updated: 2015/05/10 20:45:21 by tlepeche         ###   ########.fr       */
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
	if (ft_strlen(target) < ft_strlen
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
			if (dir_cmp(tar_dir, root) == 0) //check si on est au dessus du root;
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
