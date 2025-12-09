#include "../../include/ft_printf.h"

int	print_char(char c, t_fmt *f)
{
	int	total;
	int	spaces;

	spaces = 0;
	if (f->width > 1)
		spaces = f->width - 1;
	total = 0;
	if (!f->flag_minus)
		total += ft_putnchar(' ', spaces);
	ft_putchar(c);
	total += 1;
	if (f->flag_minus)
		total += ft_putnchar(' ', spaces);
	return (total);
}
