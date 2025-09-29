/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:14:06 by lusimon           #+#    #+#             */
/*   Updated: 2025/09/29 18:00:26 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/cub3D.h"

int	check_file(char *file)
{
	char	*str;
	int		i;
	int		j;
	int		fd;

	i = 0;
	j = 0;
	str = ".cub";
	while (file[i])
		i++;
	i = i - 4;
	j = ft_memcmp(&file[i], str, 4);
	if (j != 0)
	{
		printf("Invalid file\n");
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Couldn't open file\n");
		return (-1);
	}
	return (fd);
}

int	main(int argc, char *argv[])
{
	int	fd;

	fd = 0;
	if (argc != 2)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	fd = check_file(argv[1]);
	if (fd > 2)
		parser(fd);
	return (0);
}
