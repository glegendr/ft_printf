/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annalize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:48:35 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/08 19:00:27 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointeur(void *pointeur)
{
	unsigned char *t;
	int i;

	i = sizeof(pointeur) - 3;
	t = (unsigned char *)malloc(sizeof(pointeur) + 1);
	ft_memcpy(t, &pointeur, sizeof(pointeur));
	write(1, "0x", 2);
	while (i >= 0)
	{
		ft_putstr(ft_itoa_base(t[i], 16, 'x'));
		--i;
	}
}

void	ft_annalize(char const *restrict format, int i, va_list *v)
{
	char c;
	char *s;
	if (format[i] == 'c')
	{
		c = va_arg(*v, int);
		write(1, &c, 1);
	}
	else if (format[i] == 's')
		ft_putstr(va_arg(*v, char *));
	else if (format[i] == 'i' || format[i] == 'd' || format[i] == 'D')
		ft_putnbr(va_arg(*v, int));
	else if (format[i] == 'o')
		ft_putstr(ft_itoa_base(va_arg(*v, unsigned int), 8, '.'));
	else if (format[i] == 'x')
		ft_putstr(ft_itoa_base(va_arg(*v, int), 16, 'x'));
	else if (format[i] == 'X')
		ft_putstr(ft_itoa_base(va_arg(*v, int), 16, 'X'));
	else if (format[i] == 'p')
		ft_print_pointeur(va_arg(*v, void *));
}
