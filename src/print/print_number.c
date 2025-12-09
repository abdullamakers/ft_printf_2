/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:29:57 by abdualsh          #+#    #+#             */
/*   Updated: 2025/12/09 15:29:58 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static char	get_sign(long n, t_fmt *f)
{
	if (n < 0)
		return ('-');
	if (f->flag_plus)
		return ('+');
	if (f->flag_space)
		return (' ');
	return (0);
}

int	print_signed(long n, t_fmt *f)
{
	char	sign;
	char	*digits;
	long	val;
	int		res;

	sign = get_sign(n, f);
	val = n;
	if (n < 0)
		val = -n;
	digits = ft_utoa((unsigned long)val);
	if (!digits)
		return (-1);
	res = print_with_padding(f, sign, NULL, digits);
	free(digits);
	return (res);
}

int	print_unsigned(unsigned long n, t_fmt *f)
{
	char	*digits;
	int		res;

	digits = ft_utoa(n);
	if (!digits)
		return (-1);
	res = print_with_padding(f, 0, NULL, digits);
	free(digits);
	return (res);
}
