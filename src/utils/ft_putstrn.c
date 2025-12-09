#include "../../include/ft_printf.h"

int	ft_putstrn(const char *s, int n)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && i < n)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
