/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:11:19 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/30 00:06:04 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_ini_hex(t_st *t)
{
	if ((t->mask & CONV) == 0)
		return (ft_itoa_base((unsigned int)t->data, 16, 0));
	if ((t->mask & LL) == LL)
		return (ft_uitoa_base((unsigned long long)t->data, 16, 0));
	if ((t->mask & L) == L)
		return (ft_uitoa_base((unsigned long)t->data, 16, 0));
	if ((t->mask & J) == J)
		return (ft_uitoa_base((uintmax_t)t->data, 16, 0));
	if ((t->mask & Z) == Z)
		return (ft_uitoa_base((size_t)t->data, 16, 0));
	if ((t->mask & HH) == HH)
		return (ft_uitoa_base((unsigned char)t->data, 16, 0));
	if ((t->mask & H) == H)
		return (ft_itoa_base((unsigned short)t->data, 16, 0));
	return ("Courez mon seigneur des sarasins !");
}

char		*ft_ini_oct(t_st *t)
{
	if ((t->mask & CONV) == 0)
		return (ft_itoa_base((unsigned int)t->data, 8, 'x'));
	if ((t->mask & LL) == LL)
		return (ft_uitoa_base((unsigned long long)t->data, 8, 'x'));
	if ((t->mask & L) == L)
		return (ft_uitoa_base((unsigned long)t->data, 8, 'x'));
	if ((t->mask & J) == J)
		return (ft_uitoa_base((uintmax_t)t->data, 8, 'x'));
	if ((t->mask & Z) == Z)
		return (ft_uitoa_base((size_t)t->data, 8, 'x'));
	if ((t->mask & HH) == HH)
		return (ft_uitoa_base((unsigned char)t->data, 8, 'x'));
	if ((t->mask & H) == H)
		return (ft_uitoa_base((unsigned short)t->data, 8, 'x'));
	return ("Whalla c'est pas moi !");
}

char		*ft_ini_unsigned(t_st *t)
{
	if ((t->mask & CONV) == 0)
		return (ft_uitoa_base((unsigned int)t->data, 10, 'x'));
	if ((t->mask & LL) == LL)
		return (ft_uitoa_base((unsigned long long)t->data, 10, 'x'));
	if ((t->mask & L) == L)
		return (ft_uitoa_base((unsigned long int)t->data, 10, 'x'));
	if ((t->mask & J) == J)
		return (ft_uitoa_base((uintmax_t)t->data, 10, 'x'));
	if ((t->mask & Z) == Z)
		return (ft_uitoa_base((size_t)t->data, 10, 'x'));
	if ((t->mask & HH) == HH)
		return (ft_uitoa_base((unsigned char)t->data, 10, 'x'));
	if ((t->mask & H) == H)
		return (ft_uitoa_base((unsigned short)t->data, 10, 'x'));
	return ("N'entrez pas commissaire,c'est une vrai boucherie a l'interieur");
}

char		*ft_ini_hex_bis(t_st *t)
{
	if ((t->mask & CONV) == 0)
		return (ft_itoa_base((unsigned int)t->data, 16, 'x'));
	if ((t->mask & LL) == LL)
		return (ft_uitoa_base((unsigned long long)t->data, 16, 'x'));
	if ((t->mask & L) == L)
		return (ft_uitoa_base((unsigned long)t->data, 16, 'x'));
	if ((t->mask & J) == J)
		return (ft_uitoa_base((uintmax_t)t->data, 16, 'x'));
	if ((t->mask & Z) == Z)
		return (ft_uitoa_base((size_t)t->data, 16, 'x'));
	if ((t->mask & HH) == HH)
		return (ft_uitoa_base((unsigned char)t->data, 16, 'x'));
	if ((t->mask & H) == H)
		return (ft_itoa_base((unsigned short)t->data, 16, 'x'));
	return ("Courez mon seigneur des sarasins *bis* !");
}

void		ft_print_hex(t_st *t, int *cmpt)
{
	char	*s;
	t_vec	vec;

	vec = v_new(sizeof(char));
	if (t->prin == 'X')
		s = ft_ini_hex(t);
	else if (t->prin == 'x')
		s = ft_ini_hex_bis(t);
	else if (t->prin == 'o' || t->prin == 'O')
		s = ft_ini_oct(t);
	else
		s = ft_ini_unsigned(t);
	if (t->precision == 0 && s[0] == '0')
		return (ft_pre_is_null(t, &s, &vec, cmpt));
	t->data = s;
	ft_flag_is_sharp(t, ft_strlen(s), &vec);
	ft_flag_is_pre(&t->precision, ft_strlen(s), &vec);
	ft_flag_is_size(t, ft_strlen(s), &vec);
	if (t->size == 0)
		ft_flag_is_null(t, ft_strlen(s), &vec);
	if (t->size >= 0)
		v_append_raw(&vec, t->data, ft_strlen(s));
	v_print(&vec, 1);
	*cmpt += v_size(&vec);
	v_del(&vec);
}
