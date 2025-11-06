/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:51:42 by lusimon           #+#    #+#             */
/*   Updated: 2025/11/06 15:25:07 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

char	*remove_space_tab_before(char *line)
{
	char	*new_line;
	int		i;

	i = 0;
	new_line = NULL;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '	')
			i++;
		else
			break ;
	}
	new_line = ft_substr(line, i, ft_strlen(&line[i]));
	return (new_line);
}

char	*remove_space_tab_between(char *line)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_line = remove_space_tab_before(line);
	while (new_line[j] != '\0')
	{
		if (new_line[j] == '	')
			new_line[j] = ' ';
		j++;
	}
	return (new_line);
}

int	starts_with(char *line, char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (ft_strncmp(line, str, str_len) != 0)
		return (-1);
	return (1);
}

char	*ft_strdup_no_newline_map(const char *s1)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	if (len > 0 && s1[len - 1] == '\n')
		len--;
	p = (char *) malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	ft_memcpy(p, s1, len);
	p[len] = '\0';
	return (p);
}

char	*ft_strdup_no_newline(const char *s1)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	while (s1[i] == ' ' || s1[i] == '	')
		i++;
	s1 = s1 + i;
	len = ft_strlen(s1);
	if (len > 0 && s1[len - 1] == '\n')
		len--;
	p = (char *) malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	ft_memcpy(p, s1, len);
	p[len] = '\0';
	return (p);
}

//we need this helper_function to not include the \n
//when we look at the validity of the path
