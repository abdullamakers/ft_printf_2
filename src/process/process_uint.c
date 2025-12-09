#include "../../include/ft_printf.h"

int	process_uint(t_fmt *f, va_list *ap)
{
	unsigned long	n;

	n = (unsigned long)va_arg(*ap, unsigned int);
	return (print_unsigned(n, f));
}
