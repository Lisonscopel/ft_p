
#include "libnetwork.h"

char	*last_error(char *error)
{
	static char *last;
	
	if (error != NULL)
		last = ft_strdup(error);
	return (last);
}
