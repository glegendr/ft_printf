/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:11:19 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/22 21:20:24 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_ini_hex(t_st *t)
{
	if (t->h == 0 && t->l == 0 && t->z == 0 && t->j == 0)
		return (ft_itoa_base((unsigned int)t->data, 16, 0));
	if (t->l == 2)
		return (ft_uitoa_base((unsigned long long)t->data, 16, 0));
	if (t->l == 1)
		return (ft_uitoa_base((unsigned long)t->data, 16, 0));
	if (t->j == 1)
		return (ft_uitoa_base((uintmax_t)t->data, 16, 0));
	if (t->z == 1)
		return (ft_uitoa_base((size_t)t->data, 16, 0));
	if (t->h == 2)
		return (ft_uitoa_base((unsigned char)t->data, 16, 0));
	if (t->h == 1)
		return (ft_itoa_base((unsigned short)t->data, 16, 0));
	return ("Courez mon seigneur des sarasins !");
}
char		*ft_ini_oct(t_st *t)
{
	if (t->h == 0 && t->l == 0 && t->z == 0 && t->j == 0)
		return (ft_itoa_base((unsigned int)t->data, 8, 'x'));
	if (t->l == 2)
		return (ft_uitoa_base((unsigned long long)t->data, 8, 'x'));
	if (t->l == 1)
		return (ft_uitoa_base((unsigned long)t->data, 8, 'x'));
	if (t->j == 1)
		return (ft_uitoa_base((uintmax_t)t->data, 8, 'x'));
	if (t->z == 1)
		return (ft_uitoa_base((size_t)t->data, 8, 'x'));
	if (t->h == 2)
		return (ft_uitoa_base((unsigned char)t->data, 8, 'x'));
	if (t->h == 1)
		return (ft_uitoa_base((unsigned short)t->data, 8, 'x'));
	return ("Whalla c'est pas moi !");
}
char		*ft_ini_unsigned(t_st *t)
{
	if (t->h == 0 && t->l == 0 && t->z == 0 && t->j == 0)
		return (ft_uitoa_base((unsigned int)t->data, 2, 'x'));
	if (t->l == 2)
		return (ft_uitoa_base((unsigned long long)t->data, 10, 'x'));
	if (t->l == 1)
		return (ft_uitoa_base((unsigned long int)t->data, 10, 'x'));
	if (t->j == 1)
		return (ft_uitoa_base((uintmax_t)t->data, 10, 'x'));
	if (t->z == 1)
		return (ft_uitoa_base((size_t)t->data, 10, 'x'));
	if (t->h == 2)
		return (ft_uitoa_base((unsigned char)t->data, 2, 'x'));
	if (t->h == 1)
		return (ft_uitoa_base((unsigned short)t->data, 2, 'x'));
	return ("N'entrez pas commissaire,c'est une vrai boucherie a l'interieur");
}

char		*ft_ini_hex_bis(t_st *t)
{
	if (t->h == 0 && t->l == 0 && t->z == 0 && t->j == 0)
		return (ft_uitoa_base((unsigned int)t->data, 16, 'x'));
	if (t->l == 2)
		return (ft_uitoa_base((unsigned long long)t->data, 16, 'x'));
	if (t->l == 1)
		return (ft_uitoa_base((unsigned long)t->data, 16, 'x'));
	if (t->j == 1)
		return (ft_uitoa_base((uintmax_t)t->data, 16, 'x'));
	if (t->z == 1)
		return (ft_uitoa_base((size_t)t->data, 16, 'x'));
	if (t->h == 2)
		return (ft_uitoa_base((unsigned char)t->data, 16, 'x'));
	if (t->h == 1)
		return (ft_uitoa_base((unsigned short)t->data, 16, 'x'));
	return ("Courez mon seigneur des sarasins *bis* !");
}

void		ft_flag_is_sharp(t_st *t, int string_size, t_vec *vec, int *i)
{
	if (t->sharp == 0 || t->prin == 'u')
		return ;
	if (t->prin == 'x')
		v_append_raw(vec, "0x", 2);
	else if (t->prin == 'X')
		v_append_raw(vec, "0X", 2);
	else if (t->prin == 'b')
		v_append_raw(vec, "0b", 2);
	else if (t->prin == 'o')
	{
		v_push(vec, "0");
		*i += 1;
		return ;
	}
	*i += 2;
}

void		ft_print_hex(t_st *t, int *cmpt)
{
	char *s;
	t_vec vec;
	int i;

	i = 0;
	vec = v_new(sizeof(char));
	if (t->prin == 'X')
		s = ft_ini_hex(t);
	else if (t->prin == 'x')
		s = ft_ini_hex_bis(t);
	else if (t->prin == 'o' || t->prin == 'O')
		s = ft_ini_oct(t);
	else
		s = ft_ini_unsigned(t);
	t->data = s;
	i += ft_strlen(s);
	ft_flag_is_sharp(t, ft_strlen(s), &vec, &i);
	ft_flag_is_pre(&t->precision, ft_strlen(s), &vec, &i);
	ft_flag_is_size(t, ft_strlen(s), &vec, &i);
	if (t->size == 0)
		ft_flag_is_null(t, ft_strlen(s), &vec, &i);
	if (t->size >= 0)
		v_append_raw(&vec, t->data, ft_strlen(s));
	v_print(&vec, 1);
	*cmpt += i;
}
