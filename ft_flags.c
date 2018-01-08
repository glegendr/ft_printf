/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:06:48 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/08 21:00:54 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag_neg_next(char const *restrict format,
		int i, va_list *v, int y)
{
	t_vec vec;
	char *s;
	char *s1;

	vec = v_new(sizeof(char));
	if (format[i] == 's')
		s = va_arg(*v, char *);
	if (format[i] == 'i')
		s = ft_itoa(va_arg(*v, int));
	v_append_raw(&vec, (void *)s, ft_strlen(s));
	y -= v_size(&vec);
	if (y > 0)
	{
		s1 = ft_strnew(y);
		i = 0;
		while (i < y)
			s1[i++] = ' ';
		v_append_raw(&vec, s1, y + 1);
	}
	v_print(&vec, 1);
	v_del(&vec);
}

int		ft_flag_neg(char const *restrict format, int i, va_list *v, int ret)
{
	char *nb;
	char *tmp;
	int y;

	nb = ft_strnew(1);
	tmp = ft_strnew(1);
	nb[0] = '0';
	while (format[i] >= '0' && format[i] <= '9')
	{
		tmp[0] = format[i];
		if (nb[0] == '0')
			nb[0] = format[i];
		else
			nb = ft_strjoin(nb, tmp);
		++i;
		++ret;
	}
	y = ft_atoi(nb);
	free(tmp);
	free(nb);
	ft_flag_neg_next(format, i, v, y);
	return (ret);
}

int		ft_flags(char const *restrict format, int i, va_list *v, int ret)
{
	int index;

	if (format[i] == '#')
	{
		if (format[i + 1] == 'x')
		{
			ft_putstr("0x");
			ft_putstr(ft_itoa_base(va_arg(*v, int), 16, 'x'));
			return (ret);
		}
		ft_putstr("0X");
		ft_putstr(ft_itoa_base(va_arg(*v, int), 16, 'X'));
		return (ret);
	}
	if (format[i] == '-')
		return (ft_flag_neg(format, i + 1, v, ret));
	if (format[i] == ' ' && (format[i + 1] == 'i' || format[i + 2] == 'i'))
	{
		index = va_arg(*v ,int);
		if (format[i + 1] != '+' && index >= 0)
			ft_putchar(' ');
		else if (format[i + 1] == '+' && index >= 0)
			ft_putchar('+');
		ft_putnbr(index);
		if (format[i + 1] == '+')
			++ret;
		return (ret);
	}
	if (format[i] == '+' && (format[i + 1] == 'i' || format[i + 2] == 'i'))
	{
		index = va_arg(*v ,int);
		if (index >= 0)
			ft_putchar('+');
		ft_putnbr(index);
		if (format[i + 1] == ' ')
			++ret;
		return (ret);
	}
	write(2, "Error flag not founded", 22);
	return (1);
}
