/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   writers.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/02 19:17:57 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/06 16:51:29 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_internal.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int	write_char(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	return (write(1, &c, 1));
}

int	write_string(va_list *args)
{
	char	*s;

	s = va_arg(*args, char *);
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	write_int(va_list *args)
{
	char	*s;
	int		ret;

	s = ft_itoa(va_arg(*args, int));
	if (!s)
		return (-1);
	ret = write(1, s, ft_strlen(s));
	free(s);
	return (ret);
}

int	write_uint_base(unsigned int i, char *base)
{
	int				ret1;
	int				ret2;
	unsigned int	base_len;

	ret1 = 0;
	base_len = ft_strlen(base);
	if (i >= base_len)
		ret1 = write_uint_base(i / base_len, base);
	ret2 = write(1, &base[i % base_len], 1);
	if (ret1 < 0 || ret2 < 0)
		return (-1);
	return (ret1 + ret2);
}

int	write_uintptr(uintptr_t i)
{
	int	ret1;
	int	ret2;

	ret1 = 0;
	if (i >= 16)
		ret1 = write_uintptr(i / 16);
	ret2 = write(1, &"0123456789abcdef"[i % 16], 1);
	if (ret1 < 0 || ret2 < 0)
		return (-1);
	return (ret1 + ret2);
}
