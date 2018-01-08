/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:20:10 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/08 21:02:23 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flags(char const *restrict format, int i, va_list *v)
{
	if (format[i] == '%')
	{
		ft_putchar('%');
		return (2);
	}
	if (ft_conv(format, i))
	{
		ft_annalize(format, i, v);
		return (2);
	}
	return (ft_flags(format, i, v, 3));
}

int			ft_printf(char const *restrict format, ...)
{
	t_vec vec;
	int i;
	va_list v;
	char *c;

	c = malloc(2);
	va_start(v, format);
	vec = v_new(sizeof(char));
	i = 0;
	while (format[i])
		if (format[i] == '%')
		{
			v_print(&vec, 1);
			v_del(&vec);
			vec = v_new(sizeof(char));
			 i += ft_check_flags(format, i + 1, &v);
		}
		else
		{
			c[0] = format[i++];
			v_push(&vec, (void *)c);
		}
	v_push(&vec, (void *)"\0");
	v_print(&vec, 1);
	free(c);
	va_end(v);
	return (0);
}

int main(int argc, const char *argv[])
{
	char *s = "il y a 20 caracteres";
	ft_printf("%-87iend\n", 107);
	printf("%-87iend", 107);
}
