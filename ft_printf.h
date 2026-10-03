/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/03 17:17:07 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/03 17:23:24 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	write_string(va_list *args);

int	write_decimal(va_list *args);

int	write_unsigned(va_list *args);

int	write_hex(va_list *args, int is_uppercase);

int	write_char(va_list *args);

#endif
