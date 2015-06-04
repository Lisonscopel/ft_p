#include "libft.h"

void	ft_usage(char *prog_name, char *args)
{
	ft_putstr("Usage: ");
	ft_putstr(prog_name);
	ft_putendl(args);
	exit (-1);
}
