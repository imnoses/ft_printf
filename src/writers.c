/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   writers.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/02 19:17:57 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/03 17:21:46 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stddef.h>
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

	s = (char *)va_arg(*args, size_t);
	return (write(1, s, ft_strlen(s)));
}

int	write_decimal(va_list *args)
{
	int		i;
	char	*s;
	int		ret;

	i = va_arg(*args, int);
	s = ft_itoa(i);
	if (!s)
		return (-1);
	ret = write(1, s, ft_strlen(s));
	free(s);
	return (ret);
}

int	write_unsigned(va_list *args)
{
	return (-1);
}

int	write_hex(va_list *args, int is_uppercase)
{
	return (-1);
}
