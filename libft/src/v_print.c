/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:28:18 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/08 20:52:26 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <unistd.h>

void		v_print(t_vec *vec, int fd)
{
	int i;

	i = 0;
	while (i < vec->private_elem_nb)
	{
		write(fd, v_get(vec, i), 1);
		++i;
	}
}
