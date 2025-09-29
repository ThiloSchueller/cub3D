/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:17:18 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/21 17:58:29 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (str1[i] == str2[i]))
		i++;
	return (str1[i] - str2[i]);
}
// #include <stdio.h>
// int	main()
// {
// 	char *s1 = "Hallo Welt";
// 	char *s2 = "Hello World";
// 	printf("%d", ft_memcmp(s1, s2, 1));
// }