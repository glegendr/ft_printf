/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:48:35 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/30 23:35:29 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag_is_p_pre(t_st *t, t_vec *vec)
{
	if (t->precision == 0 && ft_strcmp((char *)v_get(vec, 0), "0") == 0)
		v_del_last(vec);
	while (t->precision > 0 + v_size(vec))
		v_push_first(vec, "0");
}

void		ft_push_pointeur(void *pointeur, int *cmpt, t_st *t)
{
	int i;
	char *s;
	int r;
	t_vec vec;

	vec = v_new(sizeof(char));
	i = sizeof(pointeur) - 1;
	while (((*((long *)&pointeur) >> i * 8) & 0xff) == 0 && i > 0)
		--i;
	r = i;
	while (i >= 0)
	{
		s = ft_itoa_base(((*((long *)&pointeur) >> i-- * 8) & 0xff), 16, 'x');
		if (ft_strlen(s) == 1 && i + 1 != r)
			v_push(&vec, "0");
		v_append_raw(&vec, s, ft_strlen(s));
		free(s);
	}
	ft_flag_is_p_pre(t, &vec);
	v_push_first(&vec ,"x");
	v_push_first(&vec ,"0");
	ft_flag_is_size(t, 0, &vec);
	v_print(&vec, 1);
	*cmpt += v_size(&vec);
	v_del(&vec);
}
