/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   helpers.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/03 16:30:37 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/03 16:39:52 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	put_unsigned(unsigned int i)
{
	int	ret;

	if (i >= 10)
		ret = put_unsigned(i / 10);
	return (ret + write(1, &"0123456789"[i % 10], 1));
}
