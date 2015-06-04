#include "libft.h"
#include <stdlib.h>

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free (*ap);
		*ap = NULL;
	}
}
