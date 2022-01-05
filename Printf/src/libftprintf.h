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

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
int		ft_printf(const char *format, ...);
void	handling_conversion(const char *format, va_list ap, int *n, size_t i);
int		ft_putnstr(const char *str, size_t n);
int		handling_int(int *flags, va_list ap, const char *format, size_t i);
char	*get_field(char *str, int *flags);

#endif
