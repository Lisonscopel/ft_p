#include "libft.h"

char				*ft_strncat(char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0' && j < n)
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
