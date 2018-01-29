/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:01:53 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/30 00:20:57 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(int argc, const char *argv[])
{
	long int i;

	i = 4294967296;
	setlocale(LC_ALL, "");
	//printf(argv[1], NULL);
	ft_printf("@moulitest: %-5d", -42);
	printf("\n");
	printf("@moulitest: %-5d", -42);
//	ft_printf(argv[1], NULL);
	return (0);
}
