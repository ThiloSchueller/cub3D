/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:04:16 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/25 13:55:19 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_makesubstring(char const *s, size_t start, size_t end)
{
	char	*substring;
	size_t	i;

	i = 0;
	substring = (char *)malloc((end - start + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	while (start < end)
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}

size_t	ft_findnext(char const *s, char c, size_t start)
{
	while (start < (ft_strlen(s) - 1))
	{
		if (s[start + 1] == c)
			return (start + 1);
		else
			start++;
	}
	return (ft_strlen(s));
}

size_t	ft_wordcount(const char *s, char c)
{
	size_t	i;
	size_t	countdoubles;
	size_t	countdelimiter;
	size_t	j;

	countdoubles = 0;
	i = 0;
	countdelimiter = 0;
	j = 0;
	if (s[0] == c)
		countdoubles = 1;
	while (i < ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] == c)
			countdoubles++;
		i++;
	}
	if (s[ft_strlen(s) - 1] == c)
		countdoubles ++;
	while (s[j] != '\0')
	{
		if (s[j++] == c)
			countdelimiter ++;
	}
	return (countdelimiter - countdoubles + 1);
}

void	freeall(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**array;
	size_t	thisone;
	size_t	wordcount;

	i = 0;
	thisone = 0;
	wordcount = 0;
	if (!(*s == '\0'))
		wordcount = ft_wordcount(s, c);
	array = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (i < wordcount)
	{
		while (s[thisone] == c)
			thisone ++;
		array[i] = ft_makesubstring(s, thisone, ft_findnext(s, c, thisone));
		if (array[i] == NULL)
			return (freeall(array, i), NULL);
		thisone = ft_findnext(s, c, thisone);
		i++;
	}
	array[i] = NULL;
	return (array);
}

// #include <stdio.h>
// int main ()
// {
// 	char const	*s = "hello!";
// 	char c = ' ';
// 	char **array;
// 	array = ft_split(s, c);
// 	printf("%s", array[0]);
// 	//free(array);
// 	//printf("%zu", ft_wordcount("1111111", ' '));
// 	return (0);
// }
// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;
// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }