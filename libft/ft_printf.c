/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:48:42 by tschulle          #+#    #+#             */
/*   Updated: 2024/11/20 13:52:15 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		re;
	int		buf;

	re = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			buf = ft_conversion(++str, args);
			if (buf == -1)
				return (-1);
			re = re + buf;
		}
		else
		{
			if (ft_putchar_fd_mod(*str, 1) == -1)
				return (-1);
			re++;
		}
		str++;
	}
	va_end (args);
	return (re);
}

int	ft_putnbr_fd_mod(int n, int fd)
{
	int		re;
	int		buf;

	re = 1;
	if (n < 0)
		re = ft_putnbr_fd_mod_outsource(n, fd);
	if ((re == 11) || (re == -1))
		return (re);
	if (n < 0)
		n = n * (-1);
	if (n > 9)
	{
		buf = ft_putnbr_fd_mod(n / 10, fd);
		if (buf == -1)
			return (-1);
		re = re + buf;
		if (ft_putchar_fd_mod((n % 10) + 48, 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar_fd_mod(n + 48, 1) == -1)
			return (-1);
	}
	return (re);
}

int	ft_putnbr_fd_mod_outsource(int n, int fd)
{
	if (n == -2147483648)
	{
		if (write(fd, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (write(fd, "-", 1) == -1)
		return (-1);
	return (2);
}

int	ft_putchar_fd_mod(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}

// #include <stdio.h>
// int	main()
// {
// 	char c = 6;
// 	char *p = &c;
// 	//printf("\n%d", printf(" %aghji "));
// 	printf("\n");
// 	printf("\n%d", ft_printf(" %ahji"));
// }
