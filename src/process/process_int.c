#include "../../include/ft_printf.h"

int	process_int(t_fmt *f, va_list *ap)
{
	long	n;

	n = (long)va_arg(*ap, int);
	return (print_signed(n, f));
}
