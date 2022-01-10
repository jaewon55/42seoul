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
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
void	ft_putnstr(const char *format, size_t i, int *result);
void	handling_conversion(const char *format, va_list ap, int *n);
int		nbr_len(ssize_t nbr, char spe, int *flags);
int		write_char(char c);
int		write_nbr(ssize_t nbr, int base, char spe);
int		write_str(char *str);

#endif
