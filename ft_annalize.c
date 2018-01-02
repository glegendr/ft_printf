/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annalize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:48:35 by glegendr          #+#    #+#             */
/*   Updated: 2017/12/28 19:02:12 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_annalize(char const *restrict format, int i, va_list *v, t_vec *vec)
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
	else if (format[i] == 'i')
		ft_putnbr(va_arg(*v, int));
}
