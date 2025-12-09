/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:29:47 by abdualsh          #+#    #+#             */
/*   Updated: 2025/12/09 15:29:50 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
