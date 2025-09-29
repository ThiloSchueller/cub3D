/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:34:13 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/23 21:15:52 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) < len)
		len = (ft_strlen(s) - start);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	while ((i < len) && (s[start + i]) != 0)
	{
		p[i] = s[start + i];
		i ++;
	}
	p[i] = '\0';
	return (p);
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
// 	char	*s = "TESTBLA";
// 	printf("%s", ft_substr(s, 400, 20));
// 	return (0);	
// }