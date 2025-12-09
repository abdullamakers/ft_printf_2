#include "../../include/ft_printf.h"

int	process_str(t_fmt *f, va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	return (print_str(s, f));
}
