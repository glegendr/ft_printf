/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:58:58 by glegendr          #+#    #+#             */
/*   Updated: 2018/01/08 19:09:09 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/vector.h"
# include "libft/includes/libft.h"
# include <stdio.h>
# include <wchar.h>
int			ft_flags(char const *restrict, int i, va_list *v, int ret);
int			ft_nb(char const *restrict, int i);
int			ft_conv(char const *restrict, int i);
void		ft_annalize(char const *restrict, int i, va_list *v);
#endif
