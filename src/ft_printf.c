#include "../include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total;

	if (!format)
		return (-1);
	va_start(ap, format);
	total = core_loop(format, &ap);
	va_end(ap);
	return (total);
}
