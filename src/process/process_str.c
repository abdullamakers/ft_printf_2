/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:30:53 by abdualsh          #+#    #+#             */
/*   Updated: 2025/12/09 15:30:54 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	process_str(t_fmt *f, va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	return (print_str(s, f));
}
