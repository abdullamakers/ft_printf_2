#include "../../include/ft_printf.h"

static int	utoa_fill(unsigned long n, char *buf)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		buf[i++] = '0' + (n % 10);
		n /= 10;
	}
	return (i);
}

char	*ft_utoa(unsigned long n)
{
	char	buf[21];
	char	*res;
	int		len;
	int		j;

	if (n == 0)
	{
		res = malloc(2);
		if (!res)
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	len = utoa_fill(n, buf);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	j = 0;
	while (--len >= 0)
		res[j++] = buf[len];
	return (res);
}
