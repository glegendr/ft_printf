/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:00:10 by glegendr          #+#    #+#             */
/*   Updated: 2018/03/01 01:22:34 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_print(t_vec *vec, char *str, int *cmpt)
{
	int		i;
	int		y;
	t_st		t;
	t_vec		v;
	char		*s;

	y = 0;
	i = 0;
	if (str == NULL)
		return NULL;
	v = v_new(sizeof(char));
	while (str[i])
	{
		if (str[i] != '%')
			v_push_int(&v, (char)str[i]);
		else
		{
			t = *(t_st *)v_get(vec, y);
			s = match_flags(&t);
			v_append_raw(&v, ft_strdup(s), ft_strlen(s));
			if (ft_strlen(s) == 0 && (t.prin == 'c' || t.prin == 'C'))
				v_push_int(&v, '\0');
			free(s);
			++y;
		}
		++i;
	}
	*cmpt = v_size(&v);
	return ((char *)v_raw(&v));
}

char			*ft_fprintf(char const *restrict format, ...)
{
	t_vec		vec;
	va_list		v;
	char		*str;
	char		*ret;
	int		cmpt;

	str = NULL;
	if (format[0] == 0)
		return (0);
	va_start(v, format);
	vec = ft_pars(format, &v, &str);
	ret = ft_print(&vec, str, &cmpt);
	free(str);
	v_del(&vec);
	return (ret);
}

int			ft_printf(char const *restrict format, ...)
{
	t_vec		vec;
	va_list		v;
	char		*str;
	char		*ret;
	int 		cmpt;

	str = NULL;
	if (!format[0])
		return (0);
	va_start(v, format);
	vec = ft_pars(format, &v, &str);
	ret = ft_print(&vec, str, &cmpt);
	write(1, ret, cmpt);
	free(ret);
	free(str);
	v_del(&vec);
	return (cmpt);
}
