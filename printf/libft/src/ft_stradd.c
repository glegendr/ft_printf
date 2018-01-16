/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:44:46 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/15 18:09:47 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_stradd(char **s, char c)
{
	char *s2;

	s2 = (char *)malloc(sizeof(char) * 2);
	s2[0] = c;
	s2[1] = 0;
	if (*s != NULL)
		*s = ft_strjoin(*s, s2);
	else
		*s = ft_strdup(s2);
	free(s2);
}
