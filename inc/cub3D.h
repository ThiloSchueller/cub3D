/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:37:37 by tschulle          #+#    #+#             */
/*   Updated: 2025/09/29 17:59:22 by lusimon          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

//main.c
int		check_file(char *file);

//parser.c
void	parser(int fd);
#endif
