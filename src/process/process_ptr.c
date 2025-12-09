/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:30:50 by abdualsh          #+#    #+#             */
/*   Updated: 2025/12/09 15:30:51 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	process_ptr(t_fmt *f, va_list *ap)
{
	unsigned long	addr;

	addr = (unsigned long)va_arg(*ap, void *);
	return (print_ptr_val(addr, f));
}
