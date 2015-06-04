#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = (unsigned char*)b;
	while (len)
	{
		*s++ = c;
		len--;
	}
	return (b);
}
