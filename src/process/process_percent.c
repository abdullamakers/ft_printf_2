#include "../../include/ft_printf.h"

int	process_percent(t_fmt *f, va_list *ap)
{
	(void)ap;
	return (print_char('%', f));
}
