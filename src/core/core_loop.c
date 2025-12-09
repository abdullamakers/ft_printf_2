/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:29:28 by abdualsh          #+#    #+#             */
/*   Updated: 2025/12/09 15:29:30 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	handle_char(char c)
{
	ft_putchar(c);
	return (1);
}

int	core_loop(const char *fmt, va_list *ap)
{
	int		i;
	int		total;
	t_fmt	f;

	i = 0;
	total = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i++;
			if (!parse_format(fmt, &i, &f))
				return (-1);
			total += dispatch_conversion(&f, ap);
			if (total < 0)
				return (-1);
		}
		else
		{
			total += handle_char(fmt[i]);
			i++;
		}
	}
	return (total);
}
