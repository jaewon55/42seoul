/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:05:52 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/09 19:05:54 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H
# define MINUS_FLAG 0
# define PLUS_FLAG 1
# define SPACE_FLAG 2
# define POUND_KEY_FLAG 3
# define ZERO_FLAG 4
# define WIDTH 5
# define PRECISION 6
# define DIGIT_MISSING -1
# define DIGIT_ZERO -2
# define WRONG_PRECISION -3
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		check_error(int *flags);
size_t	get_width(const char *format, int *flags, va_list ap);
size_t	get_precision(const char *format, int *flags, va_list ap);
void	handling_conversion(const char *format, va_list ap, int *n, size_t i);
int		handling_int(const char *format, int nbr int *flags);
int		handling_uint(const char *format, char spe, unsigned int n, int *flgas);
int		nbr_len(ssize_t nbr, char spe, int *flags);
int		write_blank(char blank, int n);
int		write_char(char c);
int		write_nbr(ssize_t nbr, int base, char specifier);
int		write_str(char *str);

#endif
