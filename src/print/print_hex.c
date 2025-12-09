#include "../../include/ft_printf.h"

int	print_hex_val(unsigned long n, t_fmt *f, int upper)
{
	char	*digits;
	char	*prefix;
	int		res;

	digits = ft_xtoa(n, upper);
	if (!digits)
		return (-1);
	prefix = NULL;
	if (f->flag_hash && n != 0)
		prefix = (upper) ? "0X" : "0x";
	res = print_with_padding(f, 0, prefix, digits);
	free(digits);
	return (res);
}
