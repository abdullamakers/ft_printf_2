/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:31:05 by abdualsh          #+#    #+#             */
/*   Updated: 2025/12/09 15:38:12 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	itoa_fill(long n, char *buf)
{
	int	i;
	int	neg;

	i = 0;
	neg = (n < 0);
	if (neg)
		n = -n;
	while (n > 0)
	{
		buf[i++] = '0' + (n % 10);
		n /= 10;
	}
	if (neg)
		buf[i++] = '-';
	return (i);
}

char	*ft_itoa(long n)
{
	char	buf[32];
	char	*res;
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
	len = itoa_fill(n, buf);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	j = 0;
	while (--len >= 0)
		res[j++] = buf[len];
	return (res);
}
