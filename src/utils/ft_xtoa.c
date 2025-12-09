/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:31:25 by abdualsh          #+#    #+#             */
/*   Updated: 2025/12/09 15:31:26 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static char	*get_digits(int upper)
{
	if (upper)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

static int	xtoa_fill(unsigned long n, char *buf, char *digits)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		buf[i++] = digits[n % 16];
		n /= 16;
	}
	return (i);
}

char	*ft_xtoa(unsigned long n, int upper)
{
	char	buf[17];
	char	*res;
	char	*digits;
	int		len;
	int		j;

	if (n == 0)
	{
		res = malloc(2);
		if (!res)
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	digits = get_digits(upper);
	len = xtoa_fill(n, buf, digits);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	j = 0;
	while (--len >= 0)
		res[j++] = buf[len];
	return (res);
}
