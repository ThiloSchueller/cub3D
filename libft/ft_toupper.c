/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:37:12 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/11 12:54:09 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
//  #include	<ctype.h>
//  #include <xlocale.h>
//  #include <stdio.h>
// int	main()
// {
// 	char c  = -555;
// 	printf("%c", ft_toupper(c));
// 	printf("%c", c);
// }