#include "libft.h"

int					ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s_1;
	unsigned char	*s_2;

	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	i = 0;
	if (s_1 == NULL)
		return (-1);
	if (s_2 == NULL)
		return (1);
	if (s_1 == NULL && s_2 == NULL)
		return (0);
	while (s_1[i] == s_2[i] && s_1[i] != '\0')
		i++;
	return (s_1[i] - s_2[i]);
}
