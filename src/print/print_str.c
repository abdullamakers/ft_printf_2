#include "../../include/ft_printf.h"

int	print_str(char *s, t_fmt *f)
{
	int	len;
	int	print_len;
	int	spaces;
	int	total;

	if (!s)
		s = "(null)";
	len = (int)ft_strlen(s);
	if (f->has_prec && f->prec < len)
		print_len = f->prec;
	else
		print_len = len;
	spaces = 0;
	if (f->width > print_len)
		spaces = f->width - print_len;
	total = 0;
	if (!f->flag_minus)
		total += ft_putnchar(' ', spaces);
	total += ft_putstrn(s, print_len);
	if (f->flag_minus)
		total += ft_putnchar(' ', spaces);
	return (total);
}
