/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:19:40 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/17 11:10:28 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (s1[i])
		++i;
	while (s2[y])
	{
		s1[i] = s2[y];
		++i;
		++y;
	}
	s1[i] = '\0';
	return (s1);
}
