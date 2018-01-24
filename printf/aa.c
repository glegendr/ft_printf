/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:00:03 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/24 21:17:20 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <unistd.h>
#include "ft_printf.h"
#include <locale.h>

void		ft_wchar_tt(wchar_t *s)
{
	int i;

	i = 0;
	while (s[i] <= 255 && s[i] >= 1)
		write(1, &s[i++], 1);
}

void		ft_wchar_t(wchar_t c)
{
	write(1, &c, 1);
}

int			main(void)
{
	setlocale(LC_ALL, "");
	wchar_t s[11] = {L'R', L'o', L'g', L'α', L' ', L'e', L's', L't', L' ', L'l', L'a'};
	ft_wchar_tt(s);
	write(1, "\n", 1);
	ft_wchar_t(s[3]);
	printf("\n%ls\n", s);
	return 0;
}
