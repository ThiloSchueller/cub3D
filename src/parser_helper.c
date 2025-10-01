/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 13:51:42 by lusimon           #+#    #+#             */
/*   Updated: 2025/10/01 13:52:24 by lusimon          ###   ########.fr       */
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

char	*ft_strdup_no_newline(const char *s1)
{
	char	*p;
	int		len;

	len = ft_strlen(s1);
	if (len > 0 && s1[len - 1] == '\n')
		len--;

	p = (char *) malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	ft_memcpy(p, s1, len);
	p[ft_strlen(s1)] = '\0';
	return (p);
}

//we need this helper_function to not include the \n
//when we look at the validity of the path