/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:57:38 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/21 18:02:06 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	while (i < ft_strlen(s1))
	{
		p[i] = s1[i];
		i++;
	}
	while ((i - ft_strlen(s1)) < ft_strlen(s2))
	{
		p[i] = s2[i - ft_strlen(s1)];
		i ++;
	}
	p[i] = '\0';
	return (p);
}

// #include <stdio.h>
// int main()
// {
// 	char	*s1 = "teil1 und";
// 	char	*s2 = " teil2";
// 	printf("%s", ft_strjoin(s1, s2));
// 	return (0);
// }