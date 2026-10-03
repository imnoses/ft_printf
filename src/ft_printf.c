/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/02 14:53:27 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/03 17:26:13 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"
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

static int	handle_var(char c, va_list *args)
{
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (write_char(args));
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
	return (count);
}

int	main(void)
{
	int	i;

	i = 18;
	ft_printf("something %d\n", i);
}
