/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:00:10 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/16 18:15:40 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print(t_vec *vec, char *str, int *cmpt)
{
	int		i;
	int		y;
	t_st	t;
	t_vec	v;

	v = v_new(sizeof(char));
	y = 0;
	i = 0;
	while (str[i++])
		if (str[i - 1] != '%')
		{
			ft_putchar(str[i - 1]);
			*cmpt += 1;
		}
		else
		{
			t = *(t_st *)v_get(vec, y);
			ft_print_flags(&t, cmpt, v);
			++y;
		}
//	v_del(&v);
}

int			ft_printf(char const *restrict format, ...)
{
	t_vec vec;
	va_list v;
	char *str;
	int cmpt;

	cmpt = 0;
	va_start(v, format);
	vec = ft_pars(format, &v, &str);
	ft_print(&vec, str, &cmpt);
	return (cmpt);
}
