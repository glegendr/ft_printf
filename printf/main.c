/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:01:53 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/30 23:34:57 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <limits.h>

void	voidi(void)
{
}

int		main(int argc, const char *argv[])
{
	short  int i;
	ft_printf("s: %s, p: %-32.16p, d: %d\n", "a string", 0, 42);
	printf("s: %s, p: %-32.16p, d: %d", "a string", 0, 42);
	setlocale(LC_ALL, "");
	return (0);
}
