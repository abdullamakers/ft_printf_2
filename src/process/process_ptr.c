#include "../../include/ft_printf.h"

int	process_ptr(t_fmt *f, va_list *ap)
{
	unsigned long	addr;

	addr = (unsigned long)va_arg(*ap, void *);
	return (print_ptr_val(addr, f));
}
