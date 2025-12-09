/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:30:03 by abdualsh          #+#    #+#             */
/*   Updated: 2025/12/09 16:04:02 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	print_ptr_val(unsigned long addr, t_fmt *f)
{
	char	*digits;
	int		res;

	if (addr == 0)
		return (print_with_padding(f, 0, "0x", "0"));
	digits = ft_xtoa(addr, 0);
	if (!digits)
		return (-1);
	res = print_with_padding(f, 0, "0x", digits);
	free(digits);
	return (res);
}
