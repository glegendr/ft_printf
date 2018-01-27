/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:17:45 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/27 15:15:13 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_restrictions.h"
#include "ft_printf.h"

void	ft_ini_struct(t_st *t)
{
	t->precision = -1;
	t->zero = 0;
	t->size = 0;
	t->mask = 0;
	t->string_size = 0;
}

void	ft_first_conv(t_st *t, int *cmpt, char c)
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

void	ft_conv_rawtoi(t_st *t, int *cmpt, char const *restrict s, int *i)
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
		{
			t->mask |= LL;
			*cmpt += 1;
		}
		else
		{
			t->mask |= L;
			*cmpt += 1;
		}
	}
	else if (c == 'h')
	{
		if ((t->mask & H) == H)
		{
			t->mask |= HH;
			*cmpt += 1;
		}
		else
		{
			*cmpt += 1;
			t->mask |= H;
		}
	}
}

void		ft_conv_is_zj(t_st *t, int *cmpt, char c)
{
	if (c == 'z')
	{
		if ((t->mask & Z) == Z)
		{
			*cmpt += 1;
		}
		else
		{
			*cmpt += 1;
			t->mask |= Z;
		}
	}
	else if (c == 'j')
	{
		if ((t->mask & J) == J)
			*cmpt += 1;
		else
		{
			*cmpt += 1;
			t->mask |= J;
		}
	}
}

int		trouver(char const *restrict s, int i, va_list *v, t_st *t)
{
	int		cmpt;

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
	return (cmpt + 1);
}

void		ft_search_conv(char const *restrict s, int i, va_list *v, t_st *t)
{
	char *s1;

	printf("%s\n", &s[i]);
	if (s[i] == 'p')
	{
		t->mask |= POINT;
		t->data = va_arg(*v, void *);
	}
	else if (s[i] == 'b')
		t->data = va_arg(*v, char *);
	else if (s[i] == 's' || s[i] == 'S')
	{
		t->mask |= STRING;
		if (s[i] == 'S' || (t->mask & L) == L)
		{
			t->mask |= L;
			t->data = va_arg(*v, wchar_t *);
		}
		else
		{
			s1 = va_arg(*v, char *);
			t->data = s1;
			t->string_size = strlen(s1);
		}
	}
	else if (s[i] == 'd' || s[i] == 'i' || s[i] == 'D')
	{
		t->mask |= DEC;
		if (s[i] == 'D')
			t->mask |= L;
		if ((t->mask & CONV) == 0)
			t->data = va_arg(*v, char *);
		else if ((t->mask & J) == J)
			t->data = (void *)va_arg(*v, intmax_t);
		else if ((t->mask & Z) == Z)
			t->data = (void *)va_arg(*v, size_t);
		else if ((t->mask & LL) == LL)
			t->data = (void *)va_arg(*v, long long int);
		else if ((t->mask & L) == L)
			t->data = (void *)va_arg(*v, long int);
		else if ((t->mask & H) == H)
			t->data = (void *)va_arg(*v, char *);
		else if ((t->mask & HH) == HH)
			t->data = (void *)va_arg(*v, char *);
	}
	else if (s[i] == '%')
		t->mask |= PC;
	else if (s[i] == 'o' || s[i] == 'O')
	{
		t->mask |= OCT;
		if (s[i] == 'O')
			t->mask |= L;
		if ((t->mask & CONV) == 0)
			t->data = va_arg(*v, char *);
		else if ((t->mask & J) == J)
			t->data = (void *)va_arg(*v, uintmax_t);
		else if ((t->mask & Z) == Z)
			t->data = (void *)va_arg(*v, size_t);
		else if ((t->mask & LL) == LL)
			t->data = (void *)va_arg(*v, unsigned long long int);
		else if ((t->mask & L) == L)
			t->data = (void *)va_arg(*v, unsigned long int);
		else if ((t->mask & H) == H)
			t->data = (void *)va_arg(*v, char *);
		else if ((t->mask & HH) == HH)
			t->data = (void *)va_arg(*v, unsigned char *);
	}
	else if (s[i] == 'u' || s[i] == 'U')
	{
		t->mask |= UNSIGNED;
		if (s[i] == 'U')
			t->mask |= L;
		t->data = va_arg(*v, char *);
	}
	else if (s[i] == 'x')
	{
		t->mask |= HEXA;
		t->data = va_arg(*v, char *);
	}
	else if (s[i] == 'X')
	{
		t->mask |= HEXAMAJ;
		t->data = va_arg(*v, char *);
	}
	else if (s[i] == 'c' || s[i] == 'C')
	{
		t->mask |= CHAR;
		if (s[i] == 'C')
			t->mask |= L;
		t->data = va_arg(*v, char *);
	}
	else
	{
		ft_putstr("Error: no convertissor Founded");
		exit(1);
	}
	t->prin = s[i];
}

t_vec	ft_pars(char const *restrict s, va_list *v, char **str)
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
			i += trouver(s, i + 1, v, &t);
			ft_search_conv(s, i, v, &t);
			i += 2;
			v_push(&vec, &t);
		}
		else
		{
			ft_stradd(str, s[i]);
			++i;
		}
	}
	va_end(*v);
	return (vec);
}
