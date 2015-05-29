#include "client.h"

int			client_report(int n, int cs)
{
	if (n == 0)
		send(cs, "ER1", 3, 0);
	if (n == 1)
		send(cs, "ER2", 3, 0);
	if (n == 2)
		ft_putendl("Usage : get <file> or <dir> [...]");
	return (-1);
}
