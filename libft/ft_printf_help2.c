/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_help2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:18:37 by tschulle          #+#    #+#             */
/*   Updated: 2024/11/04 16:48:07 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(va_list args)
{
	int	buf;

	if (write(1, "0x", 2) == -1)
		return (-1);
	buf = ft_puthex_p(va_arg(args, unsigned long));
	if (buf == -1)
		return (-1);
	return (2 + buf);
}

int	ft_puthex_p(unsigned long i)
{
	char	*array;
	int		re;
	int		buf;

	re = 1;
	array = "0123456789abcdef";
	if (i > 15)
	{
		buf = ft_puthex_p(i / 16);
		if (buf == -1)
			return (-1);
		re = re + buf;
		if (ft_putchar_fd_mod(array[i % 16], 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar_fd_mod(array[i], 1) == -1)
			return (-1);
	}
	return (re);
}
