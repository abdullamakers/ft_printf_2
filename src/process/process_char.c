#include "../../include/ft_printf.h"

int	process_char(t_fmt *f, va_list *ap)
{
	char	c;

	(void)f;
	c = (char)va_arg(*ap, int);
	return (print_char(c, f));
}
