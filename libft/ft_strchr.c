/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:09:02 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/24 15:29:11 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		else
			i++;
	}
	return (0);
}

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }
// #include <stdio.h>
// int main()
// {
// 	const char *str = "teste";
// 	printf("%s\n", ft_strchr(str, 'e'));
// 	printf("%p\n", ft_strchr(str, 'e'));
// 	printf("%p", ft_strchr(str, '\0'));
// }