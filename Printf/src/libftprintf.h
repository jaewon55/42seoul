/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:51:15 by jaewchoi          #+#    #+#             */
/*   Updated: 2021/12/24 14:10:57 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define MINUS_FLAG 0
# define PLUS_FLAG 1
# define SPACE_FLAG 2
# define POUND_KEY_FLAG 3
# define ZERO_FLAG 4
# define WIDTH 5
# define PRECISION 6
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
void	handling_conversion(const char *format, va_list ap, int *n, size_t i);
int		ft_putnstr(const char *str, size_t n);
int		handling_int(const char *format, int nbr int *flags);
size_t	get_width(const char *format, int *flags, va_list ap);
size_t	get_precision(const char *format, int *flags, va_list ap);

#endif
