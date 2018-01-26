/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:58:58 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/26 20:37:36 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "ft_restrictions.h"
# include "libft/includes/vector.h"
# include "libft/includes/libft.h"
# include <stdio.h>
# include <wchar.h>

typedef struct	s_st
{
	void		*data;
	char		prin;
	int			precision;
	int			zero;
	int			size;
	int			mask;
	int			string_size;
}				t_st;

char			*wchar_t_to_str(wchar_t c);
char			*bin_to_dec(char *s);
void			ft_print_dec(t_st *t, int *cmpt);
void			ft_print_hex(t_st *t, int *cmpt);
void			ft_print_unsigned(t_st *t, int *cmpt);
void			ft_print_oct(t_st *t, int *cmpt);
void			ft_push_pointeur(void *data, t_vec *vec, int *cmpt);
void			ft_print_flags(t_st *t, int *cmpt, t_vec vec);
void			ft_print(t_vec *vec, char *str, int *cmpt);
t_vec			ft_pars(char const *restrict s, va_list *v, char **str);
int				ft_rawtoi(char const *restrict s, int *i, int *size, int *cmpt);
int				ft_printf(char const *restrict format, ...);
int				ft_all_print(char c, va_list *v);
int				ft_flags(char const *restrict format,
		int i, va_list *v, t_st *s);
int				ft_flag_neg(char const *restrict format, int i);
void			ft_flag_is_size(t_st *t, int string_s, t_vec *v, int *i);
void			ft_flag_is_pre(int *size, int string_s, t_vec *v, int *i);
void			ft_flag_is_sharp(t_st *t, int string_s, t_vec *v, int *i);
void			ft_flag_is_null(t_st *t, int string_s, t_vec *v, int *i);
int				ft_flag_is_space(t_st *t, t_vec *vec, void *data, int *i);
int				ft_flag_is_less(char const *restrict format,
		int i, va_list *v, t_st *s);
int				ft_flag_is_more(char const *restrict format,
		int i, va_list *v, t_st *s);
int				ft_flag_is_hh(char const *restrict format,
		int i, va_list *v, t_st *s);
int				ft_flag_is_h(char const *restrict format,
		int i, va_list *v, t_st *s);
int				ft_flag_is_ll(char const *restrict format,
		int i, va_list *v, t_st *s);
int				ft_flag_is_l(char const *restrict format,
		int i, va_list *v, t_st *s);
int				ft_nb(char const *restrict format, int i);
int				ft_conv(char const *restrict format, int i);
void			ft_annalize(char const *restrict format,
		int i, va_list *v, t_st *s);
#endif
