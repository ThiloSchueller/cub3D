/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:51:42 by lusimon           #+#    #+#             */
/*   Updated: 2025/11/05 12:35:00 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

char	*remove_space_tab_before(char *line)
{
	char	*new_line;
	int		new_len;
	int		i;
	int		j;

	i = 0;
	new_len = 0;
	new_line = NULL;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '	')
			i++;
		else
			break ;
	}
	j = i;
	while (line[i] != '\0')
	{
		i++;
		new_len++;
	}
	new_line = malloc(sizeof(char) * (new_len + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[j] != '\0')
	{
		new_line[i] = line[j];
		i++;
		j++;
	}
	new_line[i] = '\0';
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

//how do I remove space and tabs in between?
//maybe I need to do ft_split
//everytime I have something written it is considered as one token
//then recreate a sentence be separating those tokens with spaces



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

int	parse_texture_color_before(t_config *data)
{
	if (data->no_set == 1 && data->so_set == 1 && data->we_set == 1
		&& data->ea_set == 1 && data->floor_set == 1 && data->ceil_set == 1)
		return (1);
	data->map_before = 1;
	return (1);
}
