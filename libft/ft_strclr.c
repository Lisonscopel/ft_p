#include "libft.h"

void	ft_strclr(char *s)
{
	int length;
	int counter;

	length = ft_strlen(s);
	counter = 0;
	while (counter < length)
	{
		*s = '\0';
		s++;
		counter++;
	}
}
