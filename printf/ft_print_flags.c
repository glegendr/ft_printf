/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:55:09 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/26 20:34:21 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_restrictions.h"

void		ft_print_s(t_st *t, int i, int *cmpt)
{
	t_vec	vec;
	int		z;

	z = t->string_size;
	vec = v_new(sizeof(char));
	if (t->precision != -1 && t->string_size > t->precision)
	{
		ft_memcut(t->data, t->precision);
		z -= t->string_size - t->precision;
		t->string_size = t->precision;
	}
	v_append_raw(&vec, t->data, t->string_size);
	while (t->size > v_size(&vec) && t->size > 0 && t->zero == 0)
		v_push_first(&vec, " ");
	while (t->size < -v_size(&vec) && t->size < 0)
		v_push(&vec, " ");
	while (t->zero > v_size(&vec) && t->size == 0)
		v_push_first(&vec, "0");
	while (t->size > v_size(&vec) && t->zero != 0)
		v_push_first(&vec, "0");
	v_print(&vec, 1);
	*cmpt += v_size(&vec);
	v_del(&vec);
}

int			ft_print_ls(wchar_t *s, int precision, int size, int zero)
{
	t_vec	vec;
	char	*s1;
	int		i;

	i = 0;
	vec = v_new(sizeof(char));
	while (s[i])
	{
		s1 = wchar_t_to_str(s[i]);
		if (precision > 0 && v_size(&vec) + ft_strlen(s1) > precision)
			break ;
		v_append_raw(&vec, s1, ft_strlen(s1));
		++i;
	}
	while (size > v_size(&vec) && size > 0 && zero == 0)
		v_push_first(&vec, " ");
	while (size < -v_size(&vec) && size < 0)
		v_push(&vec, " ");
	while (zero > v_size(&vec) && size == 0)
		v_push_first(&vec, "0");
	while (size > v_size(&vec) && zero != 0)
		v_push_first(&vec, "0");
	v_print(&vec, 1);
	return (v_size(&vec));
}

void		ft_putwchar(wchar_t c, t_st *t, int *cmpt)
{
	t_vec	vec;
	char	*s;

	vec = v_new(sizeof(char));
	s = wchar_t_to_str(c);
	if (s[0] == 0)
		*cmpt += 1;
	v_append_raw(&vec, s, ft_strlen(s));
	while (t->size > v_size(&vec) && t->size > 0)
		v_push_first(&vec, " ");
	while (t->size < -v_size(&vec) && t->size < 0)
		v_push(&vec, " ");
	v_print(&vec, 1);
	*cmpt += v_size(&vec);
	v_del(&vec);
	free(s);
}

void		ft_print_bin(t_st *t, int *cmpt)
{
	char	*s;
	int		i;
	t_vec	vec;

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
	*cmpt += v_size(&vec);
	v_print(&vec, 1);
	v_del(&vec);
}

void		ft_print_flags(t_st *t, int *cmpt, t_vec vec)
{
	if (t->prin == 's' && (t->mask & L) == 0)
		ft_print_s(t, 0, cmpt);
	else if (t->prin == 's' || t->prin == 'S')
		*cmpt += ft_print_ls(t->data, t->precision, t->size, t->zero);
	else if (t->prin == 'p')
		ft_push_pointeur(t->data, &vec, cmpt);
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
	else if ((t->mask & PC) == PC)
	{
		write(1, "%", 1);
		*cmpt += 1;
	}
}
