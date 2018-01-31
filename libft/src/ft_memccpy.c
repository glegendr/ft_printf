/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:14:53 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/23 14:57:09 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && ((unsigned char *)src)[i] != (unsigned char)c)
	{
		((unsigned char*)dst)[i] = ((unsigned char *)src)[i];
		++i;
	}
	if (i < n)
	{
		((unsigned char*)dst)[i] = ((unsigned char *)src)[i];
		return ((&((unsigned char *)dst)[i + 1]));
	}
	else
		return (NULL);
}
