/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   writers.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/02 19:17:57 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/02 19:24:07 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>

int	write_char(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	return (write(1, &c, 1));
}

int	write_string(va_list *args);
int	write_decimal(va_list *args);
int	write_unsigned(va_list *args);
int	write_hex(va_list *args, int is_uppercase);
