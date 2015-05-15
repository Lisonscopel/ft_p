#ifndef FT_P_H
# define FT_P_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# include "libft.h"
# include "get_next_line.h"
# include "libnetwork.h"

typedef	struct		s_fct
{
	char			*name;
	int				(*ptr_funct)(char **, int);
	struct s_fct	*next;
}					t_fct;

#endif
