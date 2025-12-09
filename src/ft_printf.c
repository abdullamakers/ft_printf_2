/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:31:28 by abdualsh          #+#    #+#             */
/*   Updated: 2025/12/09 15:31:29 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total;

	if (!format)
		return (-1);
	va_start(ap, format);
	total = core_loop(format, &ap);
	va_end(ap);
	return (total);
}
