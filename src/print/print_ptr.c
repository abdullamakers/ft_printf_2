#include "../../include/ft_printf.h"

int	print_ptr_val(unsigned long addr, t_fmt *f)
{
	char	*digits;
	int		res;

	if (addr == 0)
		return (print_str("(nil)", f));
	digits = ft_xtoa(addr, 0);
	if (!digits)
		return (-1);
	res = print_with_padding(f, 0, "0x", digits);
	free(digits);
	return (res);
}
