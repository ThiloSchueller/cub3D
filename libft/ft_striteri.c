/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:29:05 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/11 12:51:34 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
// void f(unsigned int i, char* c)
// {
// 	*c = *c + i;
// }
// #include <stdio.h>
// int main()
// {
// 	char s[4] = "abc";
// 	ft_striteri(s, &f);
// 	printf("%s", s);

// }