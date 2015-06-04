#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		lenght;
	char	*s_new;

	s_new = (char *)s;
	lenght = ft_strlen(s);
	while (lenght >= 0)
	{
		if (s_new[lenght] == c)
			return (s_new + lenght);
		lenght--;
	}
	return (NULL);
}
