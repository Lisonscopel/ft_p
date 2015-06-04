#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned int	digit;
	int				positive;
	int				value;

	value = 0;
	digit = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	positive = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 19)
		return (positive == 1 ? -1 : 0);
	while (ft_isdigit (*str) && *str != '\0')
	{
		digit = (int)(*str - '0');
		value = (value * 10) + digit;
		str++;
	}
	return (value * positive);
}
