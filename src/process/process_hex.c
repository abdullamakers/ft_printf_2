#include "../../include/ft_printf.h"

int	process_hex(t_fmt *f, va_list *ap)
{
	unsigned long	n;
	int				upper;

	n = (unsigned long)va_arg(*ap, unsigned int);
	upper = (f->type == 'X');
	return (print_hex_val(n, f, upper));
}
