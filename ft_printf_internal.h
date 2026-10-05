/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_internal.h                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/05 21:30:43 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/05 21:31:47 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdarg.h>
# include <stdint.h>

int	write_string(va_list *args);

int	write_int(va_list *args);

int	write_uintptr(uintptr_t i);

int	write_uint_base(unsigned int i, char *base);

int	write_char(va_list *args);

#endif
