/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdualsh <abdualsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:29:22 by abdualsh          #+#    #+#             */
/*   Updated: 2025/12/10 16:14:26 by abdualsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_fmt
{
	char	type;
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		flag_zero;
	int		flag_hash;
	int		width;
	int		prec;
	int		has_prec;
	int		zeros;
	int		spaces;
}	t_fmt;

/* main */
int		ft_printf(const char *format, ...);

/* core */
int		core_loop(const char *fmt, va_list *ap);
int		parse_format(const char *s, int *i, t_fmt *f);
int		dispatch_conversion(t_fmt *f, va_list *ap);

/* process */
int		process_char(t_fmt *f, va_list *ap);
int		process_str(t_fmt *f, va_list *ap);
int		process_ptr(t_fmt *f, va_list *ap);
int		process_int(t_fmt *f, va_list *ap);
int		process_uint(t_fmt *f, va_list *ap);
int		process_hex(t_fmt *f, va_list *ap);
int		process_percent(t_fmt *f, va_list *ap);

/* print */
int		print_char(char c, t_fmt *f);
int		print_str(char *s, t_fmt *f);
int		print_signed(long n, t_fmt *f);
int		print_unsigned(unsigned long n, t_fmt *f);
int		print_hex_val(unsigned long n, t_fmt *f, int upper);
int		print_ptr_val(unsigned long addr, t_fmt *f);
int		print_with_padding(t_fmt *f, char sign,
			const char *prefix, const char *digits);

/* utils */
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
void	ft_putchar(char c);
int		ft_putnchar(char c, int n);
int		ft_putstrn(const char *s, int n);
char	*ft_utoa(unsigned long n);
char	*ft_xtoa(unsigned long n, int upper);

#endif
