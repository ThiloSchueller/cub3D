/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:21:30 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/22 15:26:48 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_givelen(long n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		n = n * (-1);
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*p;
	size_t	len;
	long	new;

	new = (long)n;
	len = ft_givelen(new);
	if (new < 0)
	{
		n = -1;
		new = new * (-1);
		len++;
	}
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	p[len] = '\0';
	while (len > 0 && new >= 0)
	{
		p[--len] = new % 10 + '0';
		new = new / 10;
	}
	if (n == -1)
		p[0] = '-';
	return (p);
}
// #include <stdio.h>
// int main ()
// {
// 	int n;
// 	char *c;
// 	n = -2147483648;
// 	c = ft_itoa(n);
// 	printf("%s", c);
// 	return (0);
// }