/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:01:53 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/27 15:03:58 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int main(int argc, const char *argv[])
{
	setlocale(LC_ALL, "");
	printf("\t%i\n", ft_printf(argv[1], 0, L'ڛ',L'ڜ',L'ڝ', L'ڞ', L'ڟ'));
	printf("\n");
	printf("\t%i\n", printf(argv[1], 0, L'ڛ',L'ڜ',L'ڝ', L'ڞ', L'ڟ'));
	return 0;
}
