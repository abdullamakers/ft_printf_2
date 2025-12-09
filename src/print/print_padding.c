/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:30:00 by abdualsh          #+#    #+#             */
/*   Updated: 2025/12/09 15:36:39 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	get_len_d(t_fmt *f, const char *digits)
{
	int	len_d;

	len_d = (int)ft_strlen(digits);
	if (f->has_prec && f->prec == 0 && digits[0] == '0')
		len_d = 0;
	return (len_d);
}

static int	get_len_p(const char *prefix)
{
	if (prefix)
		return ((int)ft_strlen(prefix));
	return (0);
}

static void	apply_zero_flag(t_fmt *f)
{
	if (!f->has_prec && f->flag_zero && !f->flag_minus)
	{
		f->zeros += f->spaces;
		f->spaces = 0;
	}
}

static void	calc_padding(t_fmt *f, char sign,
		const char *prefix, const char *digits)
{
	int	len_d;
	int	len_p;
	int	sign_len;

	len_d = get_len_d(f, digits);
	len_p = get_len_p(prefix);
	f->zeros = 0;
	if (f->has_prec && f->prec > len_d)
		f->zeros = f->prec - len_d;
	sign_len = 0;
	if (sign)
		sign_len = 1;
	f->spaces = f->width - (len_d + f->zeros + len_p + sign_len);
	if (f->spaces < 0)
		f->spaces = 0;
	apply_zero_flag(f);
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
