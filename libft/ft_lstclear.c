/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:06:52 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/27 12:07:01 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buffer;

	while (*lst != NULL)
	{
		buffer = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = buffer;
	}
	*lst = NULL;
}
