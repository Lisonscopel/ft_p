#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*d;
	char			*s;

	d = (char *)dst;
	s = (char *)src;
	while (n--)
	{
		if (*s == c)
		{
			*d++ = *s++;
			return (d);
		}
		*d++ = *s++;
	}
	return (NULL);
}
