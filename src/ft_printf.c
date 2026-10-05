/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/02 14:53:27 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/05 21:34:09 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_internal.h"
#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

static int	next_escape_or_end(const char *s)
{
	int	i;

	i = -1;
	while (s[++i] && s[i] != '%')
		;
	return (i);
}

static int	handle_var(char c, va_list *args)
{
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (write_char(args));
	if (c == 's')
		return (write_string(args));
	if (c == 'p')
		return (write(1, "0x", 2) + write_uintptr(va_arg(*args, uintptr_t)));
	if (c == 'd' || c == 'i')
		return (write_int(args));
	if (c == 'u')
		return (write_uint_base(va_arg(*args, int), "0123456789"));
	if (c == 'x')
		return (write_uint_base(va_arg(*args, int), "0123456789abcdef"));
	if (c == 'X')
		return (write_uint_base(va_arg(*args, int), "0123456789ABCDEF"));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		next;
	int		count;
	int		res;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && s++)
			res = handle_var(*s++, &args);
		else
		{
			next = next_escape_or_end(s);
			res = write(1, s, next);
			s += next;
		}
		if (res < 0)
			return (-1);
		count += res;
	}
	va_end(args);
	return (count);
}

/*
#include <stdio.h>

int	main(void)
{
	unsigned int	u;
	char			x[] = "a string";

	u = -1;
	printf("\n=== ft ===\n");
	printf("\n--- %i ---\n", ft_printf("\tp: %p\n\ts: %s", x, x));
	printf("\n=== og ===\n");
	printf("\n--- %i ---\n", printf("\tp: %p\n\ts: %s", x, x));
	printf("\n----------\n");
	printf("\n=== ft ===\n");
	printf("\n--- %i ---\n", ft_printf("\tX: %X\n\tx: %x\n\tu: %u\n\ti: %i", u,
			u, u, u));
	printf("\n=== og ===\n");
	printf("\n--- %i ---\n", printf("\tX: %X\n\tx: %x\n\tu: %u\n\ti: %i", u, u,
			u, u));
}
*/
