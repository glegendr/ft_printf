/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:46:43 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/29 21:37:39 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcut(void *data, int size)
{
	int		i;
	void	*tmp;

	tmp = malloc(size);
	i = 0;
	while (i < size)
	{
		((unsigned char *)tmp)[i] = ((unsigned char *)data)[i];
		++i;
	}
	return (tmp);
}
