/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:16:12 by glegendr          #+#    #+#             */
/*   Updated: 2017/12/19 18:31:44 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"

void		v_push(t_vec *vec, void *elem)
{
	if (vec->private_elem_cap <= vec->private_elem_nb)
	{
		if ((vec->private_content = ft_realloc(vec->private_content,
						vec->private_elem_cap,
						(NB_ELEM_INI + vec->private_elem_cap)
						* vec->private_elem_size)) == NULL)
			return ;
		vec->private_elem_cap += NB_ELEM_INI * vec->private_elem_size;
	}
	ft_memcpy(v_get(vec, vec->private_elem_nb), elem, vec->private_elem_size);
	++vec->private_elem_nb;
}
