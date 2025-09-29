/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:02:06 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/25 13:52:52 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*strsrc;
	unsigned char	*strdst;
	size_t			i;

	i = 0;
	strsrc = (unsigned char *)src;
	strdst = (unsigned char *)dst;
	if (dst == 0 && src == 0)
		return (dst);
	if (strsrc < strdst)
	{
		while (0 < len--)
			strdst[len] = strsrc[len];
	}
	else
	{
		while (i < len)
		{
			strdst[i] = strsrc[i];
			i++;
		}
	}
	return (dst);
}
// #include <stdio.h>
// int	main()
// {
// 	unsigned char *src;
// 	unsigned char *dst;
// 	src = (unsigned char *)"Testkette";
// 	dst = (unsigned char *)src[3 , 6];
// 	ft_memmove(dst, src, 5);
// 	printf("%s\n", dst);
// }