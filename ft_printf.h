/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/03 17:17:07 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/05 13:28:41 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>

int	write_string(va_list *args);

int	write_int(va_list *args);

int	write_uintptr(uintptr_t i);

int	write_uint_base(unsigned int i, char *base);

int	ft_printf(const char *s, ...);

int	write_char(va_list *args);

#endif
