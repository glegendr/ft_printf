/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:26:53 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/30 23:19:09 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stddef.h>
# include <stdlib.h>
# define NB_ELEM_INI 32

typedef struct	s_vec
{
	void			*private_content;
	int				private_elem_nb;
	int				private_elem_size;
	int				private_elem_cap;
}				t_vec;

/*
** Create a new vector.
**
** Param:
**    elem_size: the size of each element of the vector.
*/
t_vec			v_new(int elem_size);

/*
** Copy a new element at the end of the vector.
**
** Params:
**    vec: the current vector.
**    elem: the element to add at the end of vector.
*/
void			v_push(t_vec *vec, void *elem);

/*
** Copy a new element at the start of the vector.
**
** Params:
**    vec: the current vector.
**    elem: the element to add at the end of vector.
*/
void			v_push_first(t_vec *vec, void *elem);

/*
** Copy raw at the end of the vector.
**
** Params:
**    vec: the current vector.
**    raw: the raw to add at the end of vector.
**    nb: the numbers of elems content in the raw.
*/
void			v_append_raw(t_vec *vec, void *raw, int nb);

/*
** Get the pointer of element pointed by index.
**
** Params:
**    vec: the current vector.
**    index: the index.
*/
void			*v_get(t_vec *vec, int index);

/*
** Return the element number in the vector.
**
** Param:
**    vec: the current vector.
*/
int				v_size(t_vec *vec);

/*
** Free the vector.
**
** Param:
**    vec: the vector to delete.
*/
void			v_del(t_vec *vec);

/*
** Del the last Param.
**
** Param:
**    vec: the vector to delete.
*/
void			v_del_last(t_vec *vec);

/*
** Add the second vector at the end of the first.
**
** Params:
**    vec1: first vector.
**    vec2: second vector.
*/
void			v_join(t_vec *vec1, t_vec *vec2);

/*
** Split a vector into two vector at the inex.
**
** Pararms:
**    vec: the current vector.
**    index: the index where you have to cut.
*/
t_vec			v_split(t_vec *vec, int index);

/*
** Give the raw.
**
** Param:
**    the current vector.
*/
void			*v_raw(t_vec *vec);
void			v_print(t_vec *vec, int fd);
#endif
