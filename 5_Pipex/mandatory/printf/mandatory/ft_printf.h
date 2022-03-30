/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:51:15 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/01/11 20:36:58 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putnstr(const char *format, size_t i, int *result);
void	handling_conversion(const char *format, va_list ap, int *n);
int		nbr_len(ssize_t nbr, char spe, int *flags);
int		write_char(char c);
int		write_nbr(ssize_t nbr, char spe);
int		write_str(char *str);

#endif
