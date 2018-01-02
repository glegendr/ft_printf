/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_coumpt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 16:29:54 by glegendr          #+#    #+#             */
/*   Updated: 2017/12/28 18:29:39 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//FAIRE LES FLAGS ll l j h hh ET z

int				ft_conv(char const *restrict format, int i)
{
	if (format[i] == 's' || format[i] == 'S' || format[i] == 'p' ||
			format[i] == 'd' || format[i] == 'D' || format[i] == 'i' ||
			format[i] == 'o' || format[i] == 'O' || format[i] == 'u' ||
			format[i] == 'U' || format[i] == 'x' || format[i] == 'X' ||
			format[i] == 'c' || format[i] == 'C')
		return (1);
	return (0);
}

static int		ft_nb(char const *restrict format, int i)
{
	int y;

	y = 0;
	while (format[i] <= 57 && format[i] >= 48)
	{
		++i;
		++y;
	}
	return (y);
}

static int		ft_check(char const *restrict format, int i, char c)
{
	if (format[i] == c && ft_conv(format, i + 1 + ft_nb(format, i + 1)))
		return (1);
	return (0);
}

static int		ft_flags(char const *restrict format, int i)
{
	if (ft_check(format, i, ' ') || ft_check(format, i, '-') ||
			ft_check(format, i, '0') || (format[i] == '#' &&
				(format[i + 1] == 'x' || format[i + 1] == 'X')) ||
			(format[i] == '+' && (format[i + 1 + ft_nb(format, i + 1)] == 'i' ||
								format[i + 1 + ft_nb(format, i + 1)] == 'd' ||
								format[i + 1 + ft_nb(format, i + 1)] == 'D')))
		return (1);
	return (0);
}

int				va_coumpt(char const *restrict format)
{
	int i;
	int y;

	y = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' &&
				(ft_conv(format, i + 1) || ft_flags(format, i + 1)))
			++y;
		if (format[i] == '%' && format[i + 1] == '%')
			++i;
		++i;
	}
	return (y);
}
