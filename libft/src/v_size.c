/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_size.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:17:13 by glegendr          #+#    #+#             */
/*   Updated: 2017/12/19 17:00:55 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int			v_size(t_vec *vec)
{
	return (vec->private_elem_nb);
}