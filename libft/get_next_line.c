/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:19:29 by tschulle          #+#    #+#             */
/*   Updated: 2025/11/13 14:26:50 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_makeline(char *str)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	while (str[i] != '\n')
		i++;
	new = malloc(i + 2);
	if (new == NULL)
		return (NULL);
	while (j <= i)
	{
		new[j] = str[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_gnl_read(int fd, char *str, char *buf)
{
	ssize_t	numread;
	char	*freeme;

	while (!ft_strchr(str, '\n'))
	{
		numread = read(fd, buf, BUFFER_SIZE);
		if ((numread == 0) && (*str))
		{
			ft_bzero(buf, BUFFER_SIZE + 1);
			return (str);
		}
		else if ((numread == -1) || (numread == 0))
		{
			ft_bzero(buf, BUFFER_SIZE + 1);
			return (free(str), str = NULL, NULL);
		}
		buf[numread] = '\0';
		freeme = str;
		str = ft_strjoin(str, buf);
		free(freeme);
		if (str == NULL)
			return (free(str), str = NULL, NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	char		*re;

	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	str = ft_strjoin("", buf);
	if (str == NULL)
		return (NULL);
	str = ft_gnl_read(fd, str, buf);
	if (str == NULL)
		return (free(str), NULL);
	if ((str != NULL) && (buf[0] == '\0'))
		return (str);
	ft_memmove(buf, ft_strchr(buf, '\n') + 1,
		ft_strlen(ft_strchr(buf, '\n')));
	re = ft_makeline(str);
	if (re == NULL)
		return (free(str), str = NULL, NULL);
	return (free(str), str = NULL, re);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main()
// {
// 	int	fd;
// 	char *p;
// 	int i = 0;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd != -1)
// 	{
// 		while(i++ < 40)
// 		{
// 			p = get_next_line(fd);
// 			if (!p)
// 				break;
// 			printf("%s", p);
// 			free(p);
// 			p = NULL;
// 		}
// 	}
// 	else
// 		return (-1);
// 	close(fd);
// 	return ('\0');
// }