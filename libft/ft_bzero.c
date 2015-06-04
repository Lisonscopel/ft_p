#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	char *c;

	c = s;
	if (n)
		while (n--)
			*c++ = 0;
}
