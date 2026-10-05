/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/02 14:53:27 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/05 13:04:40 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

int	next_escape_or_end(const char *s)
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

	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			res = handle_var(*(++s), &args);
			s++;
		}
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

int	main(void)
{
	unsigned int	u;
	char			x[] = "a string";

	u = -1;
	ft_printf("p: %p\ns: %s\n", x, x);
	ft_printf("X: %X\nx: %x\nu: %u\ni: %i\n", u, u, u, u);
}
