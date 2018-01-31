/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:55:09 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/31 23:12:09 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_restrictions.h"

void		ft_print_s(t_st *t, int *cmpt, int z)
{
	t_vec	vec;

	if (t->data == NULL)
		return (ft_str_is_null(t, cmpt));
	t->string_size = ft_strlen(t->data);
	z = t->string_size;
	vec = v_new(sizeof(char));
	if (t->precision != -1 && t->string_size > t->precision)
	{
		ft_memcut(t->data, t->precision);
		z -= t->string_size - t->precision;
		t->string_size = t->precision;
	}
	v_append_raw(&vec, t->data, t->string_size);
	ft_s_flags(t, &vec);
	v_print(&vec, 1);
	*cmpt += v_size(&vec);
	v_del(&vec);
}

int			ft_print_ls(wchar_t *s, int precision, int *cmpt, t_st *t)
{
	t_vec	vec;
	char	*s1;
	int		i;

	if (s == NULL)
	{
		ft_str_is_null(t, cmpt);
		return (0);
	}
	i = 0;
	vec = v_new(sizeof(char));
	while (s[i] && precision != 0)
	{
		s1 = wchar_t_to_str(s[i]);
		if (precision > 0 && (int)(v_size(&vec) + ft_strlen(s1)) > precision)
			break ;
		v_append_raw(&vec, s1, ft_strlen(s1));
		++i;
		free(s1);
	}
	ft_s_flags(t, &vec);
	v_print(&vec, 1);
	i = v_size(&vec);
	v_del(&vec);
	return (i);
}

void		ft_putwchar(wchar_t c, t_st *t, int *cmpt)
{
	t_vec	vec;
	char	*s;

	vec = v_new(sizeof(char));
	s = wchar_t_to_str(c);
	if (s[0] == 0)
	{
		while (t->size > v_size(&vec) + 1 && t->size > 0)
			v_push_first(&vec, " ");
		while (t->size == 0 && t->zero > v_size(&vec) + 1)
			v_push_first(&vec, "0");
		v_push(&vec, "\0");
	}
	v_append_raw(&vec, s, ft_strlen(s));
	while (t->size > v_size(&vec) && t->size > 0)
		v_push_first(&vec, " ");
	while (t->size < -v_size(&vec) && t->size < 0)
		v_push(&vec, " ");
	while (t->size == 0 && t->zero > v_size(&vec))
		v_push_first(&vec, "0");
	v_print(&vec, 1);
	*cmpt += v_size(&vec);
	v_del(&vec);
	free(s);
}

void		ft_print_bin(t_st *t, int *cmpt)
{
	char	*s;
	t_vec	vec;

	vec = v_new(sizeof(char));
	s = ft_itoa_base((int)t->data, 2, 0);
	t->data = s;
	ft_flag_is_sharp(t, ft_strlen(s), &vec);
	ft_flag_is_pre(&t->precision, ft_strlen(s), &vec);
	ft_flag_is_size(t, ft_strlen(s), &vec);
	if (t->size == 0)
		ft_flag_is_null(t, ft_strlen(s), &vec);
	if (t->size >= 0)
		v_append_raw(&vec, t->data, ft_strlen(s));
	*cmpt += v_size(&vec);
	v_print(&vec, 1);
	v_del(&vec);
	free(s);
}

void		ft_print_flags(t_st *t, int *cmpt)
{
	if ((t->mask & PC) == PC)
		ft_print_pc(t, cmpt);
	else if (!ft_conv(t->prin))
		ft_putwchar((char)t->prin, t, cmpt);
	else if (t->prin == 's' && (t->mask & L) == 0)
		ft_print_s(t, cmpt, 0);
	else if (t->prin == 's' || t->prin == 'S')
		*cmpt += ft_print_ls(t->data, t->precision, cmpt, t);
	else if (t->prin == 'p')
		ft_push_pointeur(t->data, cmpt, t);
	else if (t->prin == 'c' || t->prin == 'C')
		if ((t->mask & L) == L)
			ft_putwchar((wchar_t)t->data, t, cmpt);
		else
			ft_putwchar((char)t->data, t, cmpt);
	else if (t->prin == 'i' || t->prin == 'd' || t->prin == 'D')
		ft_print_dec(t, cmpt);
	else if (t->prin == 'x' || t->prin == 'X' || t->prin == 'O' ||
			t->prin == 'o' || t->prin == 'u' || t->prin == 'U')
		ft_print_hex(t, cmpt);
	else if (t->prin == 'b')
		ft_print_bin(t, cmpt);
}
