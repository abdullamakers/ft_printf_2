#include "../../include/ft_printf.h"

static void	init_fmt(t_fmt *f)
{
	f->flag_minus = 0;
	f->flag_plus = 0;
	f->flag_space = 0;
	f->flag_zero = 0;
	f->flag_hash = 0;
	f->width = 0;
	f->prec = 0;
	f->has_prec = 0;
	f->type = 0;
}

static void	parse_flags(const char *s, int *i, t_fmt *f)
{
	while (s[*i] == '-' || s[*i] == '+' || s[*i] == ' '
		|| s[*i] == '0' || s[*i] == '#')
	{
		if (s[*i] == '-')
			f->flag_minus = 1;
		else if (s[*i] == '+')
			f->flag_plus = 1;
		else if (s[*i] == ' ')
			f->flag_space = 1;
		else if (s[*i] == '0')
			f->flag_zero = 1;
		else if (s[*i] == '#')
			f->flag_hash = 1;
		(*i)++;
	}
	if (f->flag_minus)
		f->flag_zero = 0;
}

static void	parse_width(const char *s, int *i, t_fmt *f)
{
	int	w;

	w = 0;
	while (ft_isdigit(s[*i]))
	{
		w = w * 10 + (s[*i] - '0');
		(*i)++;
	}
	f->width = w;
}

static void	parse_precision(const char *s, int *i, t_fmt *f)
{
	int	p;

	if (s[*i] != '.')
		return ;
	f->has_prec = 1;
	(*i)++;
	p = 0;
	while (ft_isdigit(s[*i]))
	{
		p = p * 10 + (s[*i] - '0');
		(*i)++;
	}
	f->prec = p;
	if (f->has_prec)
		f->flag_zero = 0;
}

int	parse_format(const char *s, int *i, t_fmt *f)
{
	init_fmt(f);
	parse_flags(s, i, f);
	parse_width(s, i, f);
	parse_precision(s, i, f);
	if (!s[*i])
		return (0);
	f->type = s[*i];
	(*i)++;
	return (1);
}
