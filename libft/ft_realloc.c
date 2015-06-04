#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;

	if (!ptr)
		return (ft_memalloc(size));
	if (!size)
		return (ptr);
	if (!(ret = ft_memalloc(size)))
		return (ptr);
	ft_memcpy(ret, ptr, size);
	free(ptr);
	ptr = NULL;
	return (ret);
}
