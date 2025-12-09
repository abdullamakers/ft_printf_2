#include "../../include/ft_printf.h"

static void	calc_padding(t_fmt *f, char sign, const char *prefix,
		const char *digits)
{
	int	len_d;
	int	len_p;

	len_d = (int)ft_strlen(digits);
	len_p = (prefix) ? (int)ft_strlen(prefix) : 0;
	if (f->has_prec && f->prec == 0 && digits[0] == '0')
		len_d = 0;
	f->zeros = (f->has_prec && f->prec > len_d)
		? (f->prec - len_d) : 0;
	f->spaces = f->width - (len_d + f->zeros + len_p + (sign != 0));
	if (f->spaces < 0)
		f->spaces = 0;
	if (!f->has_prec && f->flag_zero && !f->flag_minus)
	{
		f->zeros += f->spaces;
		f->spaces = 0;
	}
}

int	print_with_padding(t_fmt *f, char sign,
		const char *prefix, const char *digits)
{
	int	total;

	calc_padding(f, sign, prefix, digits);
	total = 0;
	if (!f->flag_minus)
		total += ft_putnchar(' ', f->spaces);
	if (sign)
		ft_putchar(sign);
	if (prefix)
		total += ft_putstrn(prefix, ft_strlen(prefix));
	total += ft_putnchar('0', f->zeros);
	if (!(f->has_prec && f->prec == 0 && digits[0] == '0'))
		total += ft_putstrn(digits, ft_strlen(digits));
	if (f->flag_minus)
		total += ft_putnchar(' ', f->spaces);
	if (sign)
		total++;
	return (total);
}

