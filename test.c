/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:17:45 by glegendr          #+#    #+#             */
/*   Updated: 2017/12/28 16:16:34 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

double	test(int y, ...)
{
	int i;
	double somme;
	va_list v;

	i = 0;
	somme = 0.0;
	va_start(v, y);
	printf("%lu\t%lu\t%lu\n", sizeof(int), sizeof(double), sizeof(char *));
	while (i < y)
	{
		printf("%f\n", somme);
		somme += va_arg(v, double);
		++i;
	}
	va_end(v);
	return (somme);
}

int		main(int argc, const char *argv[])
{
	printf("%f\n", test(3.0, 2.0, 0.58, 58.0));
	return 0;
}
