/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rawtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:27:06 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/26 20:39:10 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_conv(char const *restrict format, int i)
{
	if (format[i] == 's' || format[i] == 'S' || format[i] == 'p' ||
			format[i] == 'd' || format[i] == 'D' || format[i] == 'i' ||
			format[i] == 'o' || format[i] == 'O' || format[i] == 'u' ||
			format[i] == 'U' || format[i] == 'x' || format[i] == 'X' ||
			format[i] == 'c' || format[i] == 'C' || format[i] == '%' ||
			format[i] == 'b')
		return (1);
	return (0);
}

int				ft_rawtoi(char const *restrict format,
		int *i, int *size, int *cmpt)
{
	int		y;
	int		j;

	(void)size;
	y = ft_atoi(&format[*i]);
	j = y;
	while (ft_isdigit(format[*i]))
	{
		*i += 1;
		*cmpt += 1;
	}
	*i -= 1;
	return (y);
}
