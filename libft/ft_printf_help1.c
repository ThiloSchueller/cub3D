/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_help1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:22:59 by tschulle          #+#    #+#             */
/*   Updated: 2024/11/22 18:29:53 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(const char *str, va_list args)
{
	int	re;

	re = 1;
	if (str[0] == 'c')
		re = ft_putchar_fd_mod(va_arg(args, int), 1);
	if (str[0] == 's')
		re = ft_putstr_fd_mod(va_arg(args, char *), 1);
	if (str[0] == 'p')
		re = ft_putpointer(args);
	if (str[0] == 'd')
		re = ft_putnbr_fd_mod(va_arg(args, int), 1);
	if (str[0] == 'i')
		re = ft_putnbr_fd_mod(va_arg(args, int), 1);
	if (str[0] == 'u')
		re = ft_putnbr_fd_long(va_arg(args, unsigned int), 1);
	if (str[0] == 'x')
		re = ft_puthex_low(va_arg(args, unsigned long));
	if (str[0] == 'X')
		re = ft_puthex_up(va_arg(args, unsigned int));
	if (str[0] == '%')
		re = ft_putchar_fd_mod('%', 1);
	return (re);
}

int	ft_puthex_low(unsigned int i)
{
	char	*array;
	int		re;
	int		buf;

	re = 1;
	array = "0123456789abcdef";
	if (i > 15)
	{
		buf = ft_puthex_low(i / 16);
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

int	ft_puthex_up(unsigned int i)
{
	char	*array;
	int		re;
	int		buf;

	re = 1;
	array = "0123456789ABCDEF";
	if (i > 15)
	{
		buf = ft_puthex_up(i / 16);
		if (buf == -1)
			return (-1);
		re += buf;
		if (ft_putchar_fd_mod(array[i % 16], 1) == -1)
			return (-1);
	}
	else
		if ((ft_putchar_fd_mod(array[i], 1) == -1))
			return (-1);
	return (re);
}

int	ft_putnbr_fd_long(unsigned int n, int fd)
{
	char			c;
	unsigned long	digit;
	int				re;
	int				buf;

	re = 1;
	if (n > 9)
	{
		digit = n % 10;
		buf = ft_putnbr_fd_long(n / 10, fd);
		if (buf == -1)
			return (-1);
		re = re + buf;
		c = digit + '0';
		if (write(fd, &c, 1) == -1)
			return (-1);
	}
	else
	{
		c = n + '0';
		if (write(fd, &c, 1) == -1)
			return (-1);
	}
	return (re);
}

int	ft_putstr_fd_mod(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[i] != '\0')
	{
		if (write(fd, &s[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}
