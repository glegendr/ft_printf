/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:17:45 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/29 22:34:34 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_restrictions.h"
#include "ft_printf.h"

void		ft_first_conv(t_st *t, int *cmpt, char c)
{
	if (c == '#')
	{
		t->mask = t->mask | SHARP;
		*cmpt += 1;
	}
	else if (c == ' ')
	{
		t->mask = t->mask | SPACE;
		*cmpt += 1;
	}
	else if (c == '+')
	{
		t->mask |= PLUS;
		*cmpt += 1;
	}
}

void		ft_conv_rawtoi(t_st *t, int *cmpt, char const *restrict s, int *i)
{
	if (s[*i] == '.')
	{
		*i += 1;
		*cmpt += 1;
		t->precision = ft_rawtoi(s, i, NULL, cmpt);
		if (t->precision == -1)
			t->precision = 0;
		t->mask |= PRE;
	}
	else if (s[*i] == '-')
	{
		*i += 1;
		*cmpt += 1;
		t->size = -ft_rawtoi(s, i, NULL, cmpt);
	}
	else if (s[*i] == '0')
	{
		*cmpt += 1;
		*i += 1;
		t->zero = ft_rawtoi(s, i, NULL, cmpt);
		t->mask |= ZERO;
	}
}

void		ft_conv_is_lh(t_st *t, int *cmpt, char c)
{
	if (c == 'l')
	{
		if ((t->mask & L) == L)
			t->mask |= LL;
		else
			t->mask |= L;
		*cmpt += 1;
	}
	else if (c == 'h')
	{
		if ((t->mask & H) == H)
			t->mask |= HH;
		else
			t->mask |= H;
		*cmpt += 1;
	}
}

static int	find_conv(char const *restrict s, int i, va_list *v, t_st *t)
{
	int cmpt;

	cmpt = 0;
	while (!ft_conv(s, i) && s[i])
	{
		if (s[i] == '#' || s[i] == ' ' || s[i] == '+')
			ft_first_conv(t, &cmpt, s[i]);
		else if (s[i] == '.' || s[i] == '-' || s[i] == '0')
			ft_conv_rawtoi(t, &cmpt, s, &i);
		else if (s[i] >= '1' && s[i] <= '9')
			t->size = ft_rawtoi(s, &i, NULL, &cmpt);
		else if (s[i] == 'l' || s[i] == 'h')
			ft_conv_is_lh(t, &cmpt, s[i]);
		else if (s[i] == 'z' || s[i] == 'j')
			ft_conv_is_zj(t, &cmpt, s[i]);
		else
			++cmpt;
		++i;
	}
	if (s[i] != '%' && ft_conv(s, i))
		t->data = va_arg(*v, char *);
	else
		t->mask |= PC;
	t->prin = s[i];
	return (cmpt + 2);
}

t_vec		ft_pars(char const *restrict s, va_list *v, char **str)
{
	int		i;
	t_st	t;
	t_vec	vec;

	vec = v_new(sizeof(t));
	i = 0;
	if (*str != NULL)
		*str = NULL;
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_stradd(str, '%');
			ft_ini_struct(&t);
			i += find_conv(s, i + 1, v, &t);
			if (ft_long_conv(s[i - 1]))
				t.mask |= L;
			v_push(&vec, &t);
		}
		else
			ft_stradd(str, s[i++]);
	}
	va_end(*v);
	return (vec);
}
