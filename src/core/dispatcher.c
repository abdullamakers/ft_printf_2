
#include "../../include/ft_printf.h"

int	dispatch_conversion(t_fmt *f, va_list *ap)
{
	if (f->type == 'c')
		return (process_char(f, ap));
	if (f->type == 's')
		return (process_str(f, ap));
	if (f->type == 'p')
		return (process_ptr(f, ap));
	if (f->type == 'd' || f->type == 'i')
		return (process_int(f, ap));
	if (f->type == 'u')
		return (process_uint(f, ap));
	if (f->type == 'x' || f->type == 'X')
		return (process_hex(f, ap));
	if (f->type == '%')
		return (process_percent(f, ap));
	return (-1);
}
