/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:55:09 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/17 22:07:07 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_s(t_st *t, int i, int *cmpt)
{
	t_vec vec;
	int z;

	z = t->string_size;
	vec = v_new(sizeof(char));
	if (t->precision != -1 && t->string_size > t->precision)
	{
		ft_memcut(t->data, t->precision);
		z -= t->string_size - t->precision;
		t->string_size = t->precision;
	}
	ft_flag_is_size(t, t->string_size, &vec, &z);
	if (t->size >= 0)
		v_append_raw(&vec, t->data, t->string_size);
	v_print(&vec, 1);
	*cmpt += v_size(&vec);
	v_del(&vec);
}
void		ft_print_ls(t_st *t, int i, int *cmpt)
{
	ft_putstr("On vas attendre pour les wchar_t*");
}

void		ft_putwchar(wchar_t c)
{
	ft_putstr("On vas attendre pour les wchar_t");
}

void		ft_print_bin(t_st *t, int *cmpt)
{
	char *s;
	int i;
	t_vec vec;

	vec = v_new(sizeof(char));
	s = ft_itoa_base((int)t->data, 2, 0);
	t->data = s;
	i = ft_strlen(s);
	ft_flag_is_sharp(t, ft_strlen(s), &vec, &i);
	ft_flag_is_pre(&t->precision, ft_strlen(s), &vec, &i);
	ft_flag_is_size(t, ft_strlen(s), &vec, &i);
	if (t->size == 0)
		ft_flag_is_null(t, ft_strlen(s), &vec, &i);
	if (t->size >= 0)
		v_append_raw(&vec, t->data, ft_strlen(s));
	*cmpt += i;
	v_print(&vec, 1);
	v_del(&vec);
}

void		ft_print_flags(t_st *t, int *cmpt, t_vec vec)
{
	if (t->prin == 's' && t->l == 0)
		ft_print_s(t, 0, cmpt);
	else if (t->prin == 's')
		ft_print_ls(t, 0, cmpt);
	else if (t->prin == 'p')
		ft_push_pointeur(t->data, &vec, cmpt);
	else if (t->prin == 'c' && t->l == 0)
	{
		ft_putchar((char)t->data);
		*cmpt += 1;
	}
	else if (t->prin == 'c')
	{
		ft_putwchar((wchar_t)t->data);
		*cmpt += 1;
	}
	else if (t->prin == 'i' || t->prin == 'd' || t->prin == 'D')
		ft_print_dec(t, cmpt);
	else if (t->prin == 'x' || t->prin == 'X' ||
			t->prin == 'o' || t->prin == 'u')
		ft_print_hex(t, cmpt);
	else if (t->prin == 'b')
		ft_print_bin(t, cmpt);
	else if (t->pc == 1)
	{
		write(1, "%", 1);
		*cmpt += 1;
	}
}
	/*	printf("\npc=%i\tl=%i\th=%i\tz=%i\tj=%i\tsharp=%i\tspace=%i\t"
		"plus=%i\tprecision=%i\tzero=%i\tsize=%i prin=%c\n",
		t->pc, t->l, t->h, t->z, t->j, t->sharp, t->space, t->plus,
		t->precision, t->zero, t->size, t->prin);*/
	//printf("End\n%5.sEnd\n", "salut");
