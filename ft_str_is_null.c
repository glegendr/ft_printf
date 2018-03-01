/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 23:01:52 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/01 01:54:45 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_s_flags(t_st *t, t_vec *vec)
{
	while (t->size > v_size(vec) && t->size > 0 && t->zero == 0)
		v_push_first(vec, " ");
	while (t->size < -v_size(vec) && t->size < 0)
		v_push(vec, " ");
	while (t->zero > v_size(vec) && t->size == 0)
		v_push_first(vec, "0");
	while (t->size > v_size(vec) && t->zero != 0)
		v_push_first(vec, "0");
}

void		ft_str_is_null(t_st *t, int *cmpt)
{
	if (t->precision == -1)
		t->precision = 6;
	while (t->data == NULL && t->zero-- > 0 && ++*cmpt)
		write(1, "0", 1);
	while (t->data == NULL && t->size-- > t->precision && ++*cmpt)
		write(1, " ", 1);
	if (t->precision != 0)
	{
		if (t->precision > 6)
			t->precision = 6;
		if (t->precision != -1)
		{
			write(1, "(null)", t->precision);
			*cmpt += t->precision;
		}
		else
		{
			ft_putstr("(null)");
			*cmpt += 6;
		}
	}
	while (t->data == NULL && t->size++ < -t->precision - 1 && ++*cmpt)
		write(1, " ", 1);
	return ;
}
