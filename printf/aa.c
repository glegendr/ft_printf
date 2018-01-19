/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:00:03 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/19 18:18:23 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <unistd.h>
#include "ft_printf.h"

void		ft_wchar_tt(int i, ...)
{
	wchar_t *s;
	va_list v;
	va_start(v, i);
	s = va_arg(v, wchar_t *);
	while (s[i])
		write(1, &s[i++], 1);
	va_end(v);
}

void		ft_wchar_t(int i, ...)
{
	wchar_t c;
	va_list v;
	va_start(v, i);
	c = va_arg(v, wchar_t);
	write(1, &c, 1);
	va_end(v);
}
int			main(void)
{
	wchar_t s[11] = {L'R', L'o', L'g', 130, L' ', L'e', L's', L't', L' ', L'l', L'a'};
	ft_wchar_tt(0, s);
	ft_wchar_t(0, s[3]);
	printf("\n%ls\n", s);
	return 0;
}

