/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:29:59 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/21 18:01:40 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	ft_memcpy(p, s1, ft_strlen(s1));
	p[ft_strlen(s1)] = '\0';
	return (p);
}
// #include <stdio.h>
// int main()
// {
// 	char *s = "oLOLOLo";
// 	printf("%s", ft_strdup(s));
// 	return (0);
// }