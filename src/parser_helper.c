/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:51:42 by lusimon           #+#    #+#             */
/*   Updated: 2025/10/22 16:21:01 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/cub3D.h"

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
