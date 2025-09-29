/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:00:01 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/25 13:40:52 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*strs;
	char	*strd;

	i = 0;
	strs = (char *)src;
	strd = (char *)dst;
	if (dst == 0 && src == 0)
		return (dst);
	while (i < n)
	{
		strd[i] = strs[i];
		i++;
	}
	return (dst);
}
// #include <stdio.h>
// int	main()
// {
// 	char *src = "yp";
// 	char *dst;
// //	ft_memcpy(dst, src, 2);
// //	printf("%s", dst);
// 	ft_memcpy(((void *)0), ((void *)0), 3);
// 	printf("%s", dst);
// }