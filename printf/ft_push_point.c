/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:48:35 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/24 21:45:57 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_push_0(t_vec *vec, int *cmpt)
{
		v_push(vec, (void *)"0");
		*cmpt += 1;
}

void	ft_push_0x(t_vec *vec, int *cmpt)
{
	v_append_raw(vec, (void *)"0x", 2);
	*cmpt += 2;
}

int		ft_skip_0(int *i, unsigned char *t)
{
	int y;
	char *s1;

	y = 0;
	while (ft_strcmp(s1 = ft_itoa_base(t[*i], 16, 'x'), "0") == 0)
	{
		--*i;
		y += ft_strlen(s1);
	}
	return (y + 1);
}

void	ft_push_pointeur(void *pointeur, t_vec *vec, int *cmpt)
{
	unsigned char *t;
	int i;
	char *s1;
	int y;

	i = sizeof(pointeur);
	t = (unsigned char *)malloc(sizeof(pointeur) + 1);
	ft_memcpy(t, &pointeur, sizeof(pointeur));
	y = ft_skip_0(&i, t);
	ft_push_0x(vec, cmpt);
	if (i < 0)
		ft_push_0(vec, cmpt);
	while (i >= 0)
	{
		*cmpt += ft_strlen(s1 = ft_itoa_base(t[i--], 16, 'x'));
		if (ft_strlen(s1) == 1 && i + y != sizeof(pointeur))
		{
			ft_push_0(vec, cmpt);
			v_push(vec, (void *)s1);
		}
		else
			v_append_raw(vec, s1, 2);
	}
	v_print(vec, 1);
	free(t);
}
