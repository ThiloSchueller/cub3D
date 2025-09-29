/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:29:46 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/24 16:09:56 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	result1;
	size_t	result2;
	size_t	limit;

	j = 0;
	i = ft_strlen(dst);
	result1 = i + ft_strlen(src);
	result2 = dstsize + ft_strlen(src);
	if (dstsize <= i)
		return (result2);
	limit = dstsize - i - 1;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (j < limit && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (result1);
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
// int	main()
// {
// 	char dst[20];
// 	char *src = "hellchen";
// 	ft_strlcat(dst, src, -1);
// 	printf("%s", dst);
// }