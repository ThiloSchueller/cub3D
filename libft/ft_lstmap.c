/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschulle <tschulle@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:00:48 by tschulle          #+#    #+#             */
/*   Updated: 2024/10/27 14:37:44 by tschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freeall(t_list *lst, void (*del)(void *))
{
	t_list	*buffer;

	while (lst != NULL)
	{
		buffer = lst->next;
		del(lst->content);
		free(lst);
		lst = buffer;
	}
}

t_list	*ft_makenewnode(t_list *newlist, void (*del)(void *))
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (newnode == NULL)
	{
		ft_freeall(newlist, del);
		del(newnode->content);
		free(newnode);
		return (NULL);
	}
	return (newnode);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newstart;
	t_list	*newnode;

	if (lst == NULL)
		return (NULL);
	newstart = ft_lstnew(f(lst->content));
	if (newstart == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		newnode = ft_makenewnode(newstart, del);
		newnode->content = f(lst->content);
		newnode->next = NULL;
		ft_lstadd_back(&newstart, newnode);
		lst = lst->next;
	}
	return (newstart);
}
