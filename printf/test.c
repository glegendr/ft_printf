/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:17:45 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/22 21:33:27 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_restrictions.h"
#include "ft_printf.h"

int		trouver(char const *restrict s, int i, va_list *v, t_st *t)
{
	int cmpt;
	char *s1;

	cmpt = 0;
	while (!ft_conv(s, i))
	{
		if (s[i] == '#')
		{
			if (t->sharp == 1)
			{
				ft_putstr("Error: Duplicate Flag");
				exit(1);
			}
			t->sharp = 1;
			t->mask = t->mask | SHARP;
			++cmpt;
		}
		else if (s[i] == ' ')
		{
			if (t->space == 1)
			{
				ft_putstr("Error: Duplicate Flag");
				exit(1);
			}
			t->space = 1;
			t->mask = t->mask | SPACE;
			++cmpt;
		}
		else if (s[i] == '+')
		{
			if (t->plus == 1)
			{
				ft_putstr("Error: Duplicate Flag");
				exit(1);
			}
			t->plus = 1;
			t->mask |= PLUS;
			++cmpt;
		}
		else if (s[i] == '.')
		{
			if (t->precision != -1)
			{
				ft_putstr("Error: Duplicate Flag");
				exit(1);
			}
			++i;
			++cmpt;
			t->precision  = ft_rawtoi(s, &i, NULL, &cmpt);
			if (t->precision == -1)
				t->precision = 0;
			t->mask |= PRE;
		}
		else if (s[i] == '-')
		{
			if (t->size != 0)
			{
				ft_putstr("Error: Duplicate Flag");
				exit(1);
			}
			++i;
			++cmpt;
			t->size  = -ft_rawtoi(s, &i, NULL, &cmpt);
		}
		else if (s[i] >= '1' && s[i] <= '9')
		{
			if (t->size != 0)
			{
				ft_putstr("Error: Duplicate Flag");
				exit(1);
			}
			t->size  = ft_rawtoi(s, &i, NULL, &cmpt);
		}
		else if (s[i] == '0')
		{
			if (t->zero != 0)
			{
				ft_putstr("Error: Duplicate Flag");
				exit(1);
			}
			++cmpt;
			++i;
			t->zero  = ft_rawtoi(s, &i, NULL, &cmpt);
			t->mask |= ZERO;
		}
		else if (s[i] == 'l')
		{
			if (t->l == 2)
			{
				ft_putstr("Error: Duplicate Flag");
				exit(1);
			}
			if (t->l == 1)
			{
				t->l = 2;
				t->mask |= LL;
				++i;
				++cmpt;
				continue;
			}
			t->l = 1;
			t->mask |= L;
			++cmpt;
		}
		else if (s[i] == 'h')
		{
			if (t->h == 2)
			{
				ft_putstr("Error: Duplicate Flag");
				exit(1);
			}
			if (t->h == 1)
			{
				t->h = 2;
				t->mask |= HH;
				++i;
				++cmpt;
				continue;
			}
			++cmpt;
			t->h = 1;
			t->mask |= H;
		}
		else if (s[i] == 'z')
		{
			if (t->z != 0)
			{
				ft_putstr("Error: Duplicate Flag");
				exit(1);
			}
			++cmpt;
			t->z = 1;
			t->mask |= Z;
		}
		else if (s[i] == 'j')
		{
			if (t->j != 0)
			{
				ft_putstr("Error: Duplicate Flag");
				exit(1);
			}
			++cmpt;
			t->j = 1;
			t->mask |= J;
		}
		else
		{
			ft_putstr("Error: Flag no found");
			exit(1);
		}
		++i;
	}
		//ft_putstr(&s[i]);
		//ft_putchar('\n');
	if (s[i] == 'p')
	{
		t->mask |= POINT;
		t->data = va_arg(*v, void *);
	}
	else if (s[i] == 'b')
		t->data = va_arg(*v, char *);
	else if (s[i] == 's')
	{
		t->mask |= STRING;
		s1 = va_arg(*v, char *);
		t->data = s1;
		t->string_size = strlen(s1);
	}
	else if (s[i] == 'd' || s[i] == 'i')
	{
		t->mask |= DEC;
		if (t->l == 0 && t->h == 0 && t->j == 0 && t->z == 0)
		t->data = va_arg(*v, char *);
		else if (t->j == 1)
		t->data = (void *)va_arg(*v, intmax_t);
		else if (t->z == 1)
		t->data = (void *)va_arg(*v, size_t);
		else if (t->l == 1)
		t->data = (void *)va_arg(*v, long int);
		else if (t->l == 2)
		t->data = (void *)va_arg(*v, long long int);
		else if (t->h == 1)
		t->data = (void *)va_arg(*v, char *);
		else if (t->h == 2)
		t->data = (void *)va_arg(*v, char *);
	}
	else if (s[i] == '%')
	{
		t->pc = 1;
		t->mask |= PC;
	}
	else if (s[i] == 'o')
	{
		t->mask |= OCT;
		if (t->l == 0 && t->h == 0 && t->j == 0 && t->z == 0)
		t->data = va_arg(*v, char *);
		else if (t->j == 1)
		t->data = (void *)va_arg(*v, uintmax_t);
		else if (t->z == 1)
		t->data = (void *)va_arg(*v, size_t);
		else if (t->l == 1)
		t->data = (void *)va_arg(*v, unsigned long int);
		else if (t->l == 2)
		t->data = (void *)va_arg(*v, unsigned long long int);
		else if (t->h == 1)
		t->data = (void *)va_arg(*v, char *);
		else if (t->h == 2)
		t->data = (void *)va_arg(*v, unsigned char *);
	}
	else if (s[i] == 'u')
	{
		t->mask |= UNSIGNED;
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
	else if (s[i] == 'c')
	{
		t->mask |= CHAR;
		t->data = va_arg(*v, char *);
	}
	else if (s[i] == 'D')
	{
		t->mask |= DEC;
		t->l = 1;
		t->data = (void *)va_arg(*v, long int);
	}
	else if (s[i] == 'O')
	{
		t->mask |= OCT;
		t->l = 1;
		t->data = (void *)(va_arg(*v, unsigned long));
	}
	else if (s[i] == 'U')
	{
		t->mask |= UNSIGNED;
		t->l = 1;
		t->data = (void *)(va_arg(*v, unsigned long));
	}
	else
	{
		ft_putstr("Error: no convertissor Founded");
		exit(1);
	}
	t->prin = s[i];
	return (cmpt + 2);
}

void	ft_ini_struct(t_st *t)
{
	t->pc = 0;
	t->l = 0;
	t->h = 0;
	t->z = 0;
	t->j = 0;
	t->sharp = 0;
	t->space = 0;
	t->plus = 0;
	t->precision = -1;
	t->zero = 0;
	t->size = 0;
	t->mask = 0;
	t->string_size = 0;
}


t_vec	ft_pars_end(t_vec vec)
{
	int y;
	t_st t;
	int i;
	int bon;

	bon = 0;
	y = 0;
	while (y < v_size(&vec))
	{
		i = 0;
		t = *(t_st *)v_get(&vec, y);
		while (i++ < 8)
			if ((t.mask | g_restrictions[i - 1]) == g_restrictions[i - 1])
				++bon;
		++y;
	}
	return (vec);
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
			v_push(&vec, &t);
		}
		else
		{
			ft_stradd(str, s[i]);
			++i;
		}
	}
	va_end(*v);
	return (ft_pars_end(vec));
}

int		main(int argc, const char *argv[])
{
	t_st s;
	unsigned long long i = 18446744073709551615;
	wchar_t s1[15] ={L'R', L'o', L'g', 130, L' ', L'e', L's', L't', L' ', L'l', L'a', L'.' , 130, L'o', L't'};
	if (argc != 1)
	{
		ft_printf((char *)argv[1], 0, s1, i);
		write(1, "\n", 1);
		printf((char *)argv[1], 0, s1, i);
	}
	else
		ft_putstr("Error: No input");
	return (0);
}
