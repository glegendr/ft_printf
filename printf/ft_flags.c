/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 20:31:04 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/26 20:35:35 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_is_size(t_st *t, int string_size, t_vec *vec, int *i)
{
	if (t->size > 0 && *i < t->size)
	{
		while (*i < t->size)
		{
			v_push_first(vec, " ");
			*i += 1;
		}
	}
	else if (t->size < 0)
	{
		v_append_raw(vec, t->data, string_size);
		while (*i < -t->size)
		{
			v_push(vec, " ");
			*i += 1;
		}
	}
}

void	ft_flag_is_sharp(t_st *t, int string_size, t_vec *vec, int *i)
{
	(void)string_size;
	if ((t->mask & SHARP) == 0 || t->prin == 'u')
		return ;
	if (t->prin == 'x')
		v_append_raw(vec, "0x", 2);
	else if (t->prin == 'X')
		v_append_raw(vec, "0X", 2);
	else if (t->prin == 'b')
		v_append_raw(vec, "0b", 2);
	else if (t->prin == 'o')
	{
		v_push(vec, "0");
		*i += 1;
		return ;
	}
	*i += 2;
}
