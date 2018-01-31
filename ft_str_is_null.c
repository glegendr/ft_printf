/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 23:01:52 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/31 23:10:11 by glegendr         ###   ########.fr       */
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
	if (t->precision != 0)
	{
		ft_putstr("(null)");
		*cmpt += 6;
		return ;
	}
	while (t->data == NULL && t->zero-- > 0 && ++*cmpt)
		write(1, "0", 1);
	return ;
}