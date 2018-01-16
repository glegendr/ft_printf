/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:54:12 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/16 20:33:12 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag_is_size(t_st *t, int string_size, t_vec *vec, void *data)
{
	int i;

	i = 0;
	if (t->size > 0 && string_size < t->size)
	{
		if (t->precision > string_size)
		while (i++ < t->size - t->precision)
			v_push(vec, " ");
		if (t->precision < string_size)
		while (i++ < t->size - string_size)
			v_push(vec, " ");
		t->size = 0;
	}
	else if (t->size < 0 && string_size < -t->size)
	{
		v_append_raw(vec, data, string_size);
		while (i++ < -t->size - string_size)
			v_push(vec, " ");
	}
	else
		v_append_raw(vec, data, string_size);
}

void		ft_flag_is_pre(int *size, int string_size, t_vec *vec, void *l)
{
	int i;

	i = 0;
	if (*size == -1)
		return ;
	if (string_size < *size)
	{
		while (i++ < *size - string_size)
			v_push(vec, "0");
	}
	*size = i - 1;
}

void		ft_flag_is_space(int *space, t_vec *vec, void *data)
{
	if (*space == 0)
		return ;
	if (((char *)data)[0] == '-')
	{
		*space = 0;
		return ;
	}
	v_push(vec, " ");
}

void		ft_print_dec(t_st *t, int *cmpt)
{
	char *s;
	t_vec vec;
	int i;

	i = 0;
	vec = v_new(sizeof(char));
	if (t->h == 0 && t->l == 0 && t->z == 0 && t->j == 0)
		s =  bin_to_dec(ft_itoa_base((int)t->data, 2, 0));
	else if (t->h == 1)
		s = bin_to_dec(ft_itoa_base((short int)t->data, 2, 0));
	else if (t->l == 1)
		s = bin_to_dec(ft_itoa_base((long int)t->data, 2, 0));
	else if (t->l == 2)
		s = bin_to_dec(ft_itoa_base((long long int)t->data, 2, 0));
	if (t->size > 0)
		ft_flag_is_size(t, ft_strlen(s), &vec, s);
	ft_flag_is_space(&t->space, &vec, s);
	ft_flag_is_pre(&t->precision, ft_strlen(s) + t->space, &vec, s);
	if (t->size < 0)
		ft_flag_is_size(t, ft_strlen(s), &vec, s);
	else if (t->size == 0)
		v_append_raw(&vec, s, ft_strlen(s));
	v_print(&vec, 1);
}
