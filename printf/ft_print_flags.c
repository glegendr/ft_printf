/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:55:09 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/24 23:55:15 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_restrictions.h"

void		ft_print_s(t_st *t, int i, int *cmpt)
{
	t_vec vec;
	int z;
	(void)i;
	z = t->string_size;
	vec = v_new(sizeof(char));
	if (t->precision != -1 && t->string_size > t->precision)
	{
		ft_memcut(t->data, t->precision);
		z -= t->string_size - t->precision;
		t->string_size = t->precision;
	}
	ft_flag_is_size(t, t->string_size, &vec, &z);
	if (t->size >= 0)
		v_append_raw(&vec, t->data, t->string_size);
	v_print(&vec, 1);
	*cmpt += v_size(&vec);
	v_del(&vec);
}
int		ft_print_ls(wchar_t *s, int precision, int size)
{
	int i;

	i = 0;
	while (s[i] < 256 && s[i++] > 0);
	if (precision == -1)
		precision = i;
	if (precision < i)
		while (size-- > precision)
		write(1, " ", 1);
	else
		while (size-- >= i)
		write(1, " ", 1);
	i = 0;
	while (s[i] <= 255 && s[i] >= 1 && i < precision)
		write(1, &s[i++], 1);
	if (size < 0)
		while (++size < -i)
			write(1, " ", 1);
	return (i);
}

void		ft_putwchar(wchar_t c, t_st *t, int *cmpt)
{
	while (t->size > 1 && (t->mask & ZERO) == 0)
	{
		write(1, " ", 1);
		--t->size;
		*cmpt += 1;
	}
	while (t->zero > 1 && t->size == 0)
	{
		write(1, "0", 1);
		--t->zero;
		*cmpt += 1;
	}
	while (t->size > 1 && (t->mask & ZERO) != 0)
	{
		write(1, "0", 1);
		--t->size;
		*cmpt += 1;
	}
	char *u;
//	printf("%s\t%i\n", ft_itoa_base(c, 2, '.'), c);
		// Changer mon bin_to_wchar_t pour que toutes les parties du wchar_t soit sur
		// 8 bits soit de droite a gauche: un 0 puis le reste en 1
		// par exemple 11010 deviens 1->1->0->11010
		// et 1010 110001 111111 deviens 11101010 10110001 10111111
		// Transformer en Hexadecimal donne EA B1 BF
		// ce qui est en Exemple :D
//	u =  malloc(sizeof(char) * 5);
//	u[0] = 0xEA;
//	u[1] = 0xB1;
//	u[2] = 0xBF;
//	u[3] = 0;
//	ft_putstr(u);
	write(1, &c, 1);
	while (t->size < -1)
	{
		write(1, " ", 1);
		++t->size;
		*cmpt += 1;
	}
}

void		ft_print_bin(t_st *t, int *cmpt)
{
	char *s;
	int i;
	t_vec vec;

	vec = v_new(sizeof(char));
	s = ft_itoa_base((int)t->data, 2, 0);
	t->data = s;
	i = ft_strlen(s);
	ft_flag_is_sharp(t, ft_strlen(s), &vec, &i);
	ft_flag_is_pre(&t->precision, ft_strlen(s), &vec, &i);
	ft_flag_is_size(t, ft_strlen(s), &vec, &i);
	if (t->size == 0)
		ft_flag_is_null(t, ft_strlen(s), &vec, &i);
	if (t->size >= 0)
		v_append_raw(&vec, t->data, ft_strlen(s));
	*cmpt += i;
	v_print(&vec, 1);
	v_del(&vec);
}

void		ft_print_flags(t_st *t, int *cmpt, t_vec vec)
{
	if (t->prin == 's' && (t->mask & L) == 0)
		ft_print_s(t, 0, cmpt);
	else if (t->prin == 's' || t->prin == 'S')
		*cmpt += ft_print_ls((wchar_t *)t->data, t->precision, t->size);
	else if (t->prin == 'p')
		ft_push_pointeur(t->data, &vec, cmpt);
	else if (t->prin == 'c' || t->prin == 'C')
	{
		if ((t->mask & L) == L)
			ft_putwchar((wchar_t)t->data, t, cmpt);
		else
			ft_putwchar((char)t->data, t, cmpt);
		*cmpt += 1;
	}
	else if (t->prin == 'i' || t->prin == 'd' || t->prin == 'D')
		ft_print_dec(t, cmpt);
	else if (t->prin == 'x' || t->prin == 'X' || t->prin == 'O' ||
			t->prin == 'o' || t->prin == 'u' || t->prin == 'U')
		ft_print_hex(t, cmpt);
	else if (t->prin == 'b')
		ft_print_bin(t, cmpt);
	else if ((t->mask & PC) == PC)
	{
		write(1, "%", 1);
		*cmpt += 1;
	}
}
	/*	printf("\npc=%i\tl=%i\th=%i\tz=%i\tj=%i\tsharp=%i\tspace=%i\t"
		"plus=%i\tprecision=%i\tzero=%i\tsize=%i prin=%c\n",
		t->pc, t->l, t->h, t->z, t->j, t->sharp, t->space, t->plus,
		t->precision, t->zero, t->size, t->prin);*/
	//printf("End\n%5.sEnd\n", "salut");
