/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:44:48 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/25 13:56:01 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	j;

	j = 0;
	new = (char *)malloc((ft_strlen(s) + 1 * sizeof(char)));
	if (new == NULL)
		return (NULL);
	while (j < ft_strlen(s))
	{
		new[j] = f(j, s[j]);
		j++;
	}
	new[j] = '\0';
	return (new);
}

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;
// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }
// char ft_test(unsigned int i, char c)
// {
// 	char	p;
// 	p = c + i;
// 	return (p);
// }
// #include <stdio.h>
// int	main()
// {
// 	char *s1 = "Eeee";
// 	char *s2 = ft_strmapi(s1 , ft_test);
// 	printf("%s", s2);
// 	return (0);
// }