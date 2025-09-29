/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:57:25 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/18 15:01:49 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	cnew;

	cnew = (unsigned char)c;
	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == cnew)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// int	main()
// {
// 	char *str = "Broomsticks";
// 	int c = 'B';
// 	size_t len = 2;
// 	printf("%s", ft_memchr(str, c , len));
// }