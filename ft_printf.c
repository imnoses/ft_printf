/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/02 14:53:27 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/02 19:20:47 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

int	next_escape_or_end(const char *s)
{
	int	i;

	i = -1;
	while (s[++i] && s[i] != '%')
		;
	if (s[i])
		return (-1);
	return (i);
}

int			write_char(va_list *args);
int			write_string(va_list *args);
int			write_decimal(va_list *args);
int			write_unsigned(va_list *args);
int			write_hex(va_list *args, int is_uppercase);

static int	handle_var(char c, va_list *args)
{
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (write_char(args));
	// return (ft_putchar_fd((char)va_arg(*args, int), 1), 1);
	if (c == 's')
		return (write_string(args));
	if (c == 'p')
		return (write(1, "0x", 2) + write_hex(args, 0));
	if (c == 'd' || c == 'i')
		return (write_decimal(args));
	if (c == 'u')
		return (write_unsigned(args));
	if (c == 'x')
		return (write_hex(args, 0));
	if (c == 'X')
		return (write_hex(args, 1));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		next;
	int		count;
	int		res;

	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			res = handle_var(*(s++), &args);
			if (res < 0)
				return (-1);
			count += res;
		}
		next = next_escape_or_end(s);
		count += write(1, s, next);
		s += next;
	}
}
