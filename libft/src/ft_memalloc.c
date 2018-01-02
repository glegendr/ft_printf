/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:40:29 by glegendr          #+#    #+#             */
/*   Updated: 2017/11/24 13:44:48 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	i = 0;
	if ((mem = (void *)malloc(sizeof(*mem) * size)) == 0)
		return (0);
	while (i < size)
	{
		((char *)mem)[i] = 0;
		++i;
	}
	return (mem);
}
