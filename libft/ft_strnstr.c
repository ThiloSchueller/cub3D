/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:37:28 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/24 17:53:43 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr( const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while ((haystack[i] != '\0') && (i < len))
	{
		if (haystack[i++] == needle[j++])
		{
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j]);
		}
		else if (j != 0)
			i = i - j + 1;
		else
			i++;
		if (haystack[i - 1] != needle[j - 1])
			j = 0;
	}
	return (0);
}

// #include <stdio.h>
// int	main()
// {
// 	const char *haystack = "aaabcabcd";
// 	const char *needle = "aabc";
// 	printf("%s", ft_strnstr(haystack, needle, -1));
// }
