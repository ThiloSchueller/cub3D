/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:19:50 by tschulle          #+#    #+#             */
/*   Updated: 2025/04/17 12:09:17 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long	i;

	i = (long)ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (0);
}

/* size_t	ft_strlen(const char *str)
 {
 	size_t	i;
 	i = 0;
 	while (str[i] != '\0')
 		i++;
 	return (i);
 }
 #include <stdio.h>
 int main()
 {
 	const char *s = "Haloo234SSS";
 	printf("%s", ft_strrchr(s, 'h' + 256));
}*/