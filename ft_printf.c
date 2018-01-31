/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:00:10 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/31 22:57:48 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print(t_vec *vec, char *str, int *cmpt)
{
	int		i;
	int		y;
	t_st	t;
	t_vec	v;

	y = 0;
	i = 0;
	if (str == NULL)
		return ;
	while (str[i++])
		if (str[i - 1] != '%')
		{
			ft_putchar(str[i - 1]);
			*cmpt += 1;
		}
		else
		{
			v = v_new(sizeof(char));
			t = *(t_st *)v_get(vec, y);
			ft_print_flags(&t, cmpt);
			v_del(&v);
			++y;
		}
}

int			ft_printf(char const *restrict format, ...)
{
	t_vec		vec;
	va_list		v;
	char		*str;
	int			cmpt;

	str = NULL;
	if (format[0] == 0)
		return (0);
	cmpt = 0;
	va_start(v, format);
	vec = ft_pars(format, &v, &str);
	ft_print(&vec, str, &cmpt);
	free(str);
	v_del(&vec);
	return (cmpt);
}
