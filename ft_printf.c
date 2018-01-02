/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:20:10 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/02 20:44:45 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flags(char const *restrict format, int i, va_list *v, t_vec *vec)
{
	if (format[i] == '#')
	{
		if (format[i + 1] != 'X' && format[i + 1] != 'x')
			return (3);
		if (format[i + 1] == 'x')
		{
			ft_putstr("0x");
			ft_putstr(ft_itoa_base(va_arg(*v, int), 16, 'x'));
			return (3);
		}
			ft_putstr("0X");
			ft_putstr(ft_itoa_base(va_arg(*v, int), 16, 'X'));
			return (3);
	}
	return (1);
}

int		ft_check_flags(char const *restrict format, int i,
		va_list *v, t_vec *vec)
{
	if (format[i] == '%')
	{
		ft_putchar('%');
		return (2);
	}
	if (ft_conv(format, i))
	{
		ft_annalize(format, i, v, vec);
		return (2);
	}
	return (ft_flags(format, i, v, vec));
	return (2);
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
			 i += ft_check_flags(format, i + 1, &v, &vec);
		}
		else
		{
			c[0] = format[i++];
			v_push(&vec, (void *)c);
		}
	v_push(&vec, (void *)"\0");
	v_print(&vec, 1);
	free(c);
	return (0);
}

int main(int argc, const char *argv[])
{
	//ft_printf("");
	//printf("%i\n", printf("%s je suis Francais\n", "salutt")); // 24 char ecris
	ft_printf("%s %c%c%c%c%c%c\t%o\n", "salut", 'H', 'e', 'l', '\0', 'l', 'o', 8);
	printf("%s %c%c%c%c%c%c\t%o\n", "salut", 'H', 'e', 'l', '\0', 'l', 'o', 8);

	return 0;
}