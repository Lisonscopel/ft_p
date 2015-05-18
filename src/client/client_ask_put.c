/////////// CLIENT, ENVOI /////////
//	buff[0] == 'Q' -> question -> fichier deja existant
//	buff[0] == 'R' -> demande pour le rename
//	buff[0] == 'K' -> fin des question / pas de question et fichier existant -> debut de la copie
//	buff[0]	== 'S' -> STOP fichier non existant


// FONCTION PRESK FONCTIONNELLE, REVOIR QUAND ON ENVOI DE LA MERDE LORS DE LA DEMANDE (a, r, o)
// + REVOIR LORS DE LA RECREATION DUN MEME FICHIER (PUT MAKEFILE x 2 PAR EX)
#include "client.h"

int		ask_put(char **path, int socket)
{
	int			ret;
	char		buff[255];
	char		*line;
	int			fd;
	struct stat	st;
	char		*size;

	if (path[1])
	{
		if ((fd = open(path[1], O_RDONLY)) != -1)
		{
			fstat(fd, &st);
			size = ft_itoa(st.st_size);
			send(socket, size, ft_strlen(size), 0);
			ft_bzero(buff, 255);
			while (buff[0] != 'K' && buff[0] != 'S')
			{
				ret = recv(socket, buff, 1, 0);
				buff[ret] = '\0';
				if (buff[0] == 'Q')
				{
					ft_putendl("\033[0;1mFile already exists\033[0m");
					ft_putstr("(A)bort, (R)ename, (O)verwrite ?");
					get_next_line(0, &line);
					send(socket, line, ft_strlen(line), 0);
					if (line[0] == ft_tolower('a'))
					{
						close(fd);
						return (1);
					}
					else if (line[0] == ft_tolower('r'))
					{
						ft_putstr("New name :");
						get_next_line(0, &line);
						send(socket, line, ft_strlen(line), 0);
					}
				}
			}
			if (buff[0] == 'K')
			{
				while ((ret = read(fd, buff, 255)) > 0)
				{
					send(socket, buff, ret, 0);
					recv(socket, line, 1, 0);
				}
				close(fd);
				return (1);
			}
		}
		ft_putendl(path[1]);
		ft_putendl("ERROR put: file doesn't exist");
		send(socket, "ERROR", 5, 0);
		return (0);
	}
	ft_putendl("ERROR put: too few arguments");
	send(socket, "ERROR", 5, 0);
	return (0);
}
