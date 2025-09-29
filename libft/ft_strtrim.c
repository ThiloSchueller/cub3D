/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:13:34 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/24 18:22:56 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_givestart(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((s1[i] != '\0') && (set[j] != '\0'))
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

size_t	ft_giveend(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	while ((i > 0) && (set[j] != '\0'))
	{
		if (s1[i - 1] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	i;

	i = 0;
	if (ft_giveend(s1, set) < ft_givestart(s1, set))
	{
		p = malloc(1);
		if (p == 0)
			return (0);
		*p = '\0';
		return (p);
	}
	p = (char *)malloc(((ft_giveend(s1, set) - ft_givestart(s1, set)) + 1)
			* sizeof(char));
	if (p == 0)
		return (0);
	while (i < (ft_giveend(s1, set) - ft_givestart(s1, set)))
	{
		p[i] = s1[ft_givestart(s1, set) + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

// #include <stdio.h>
// int main()
// {
// 	char *s1 = "   xxx   xxx";
// 	char *set = " x";
// 	printf("%s", ft_strtrim(s1, set));
// 	return (0);
// }