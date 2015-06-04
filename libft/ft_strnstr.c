#include "libft.h"

char				*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		k = i;
		while ((s1[k] == s2[j]) && k < n)
		{
			k++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
