/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 18:52:40 by cchauvie          #+#    #+#             */
/*   Updated: 2014/03/07 14:27:24 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(*new));
	if (new)
	{
		if (content && content_size)
		{
			new->content = ft_memdup(content, content_size);
			new->content_size = content_size;
		}
		else
		{
			new->content = NULL;
			new->content_size = 0;
		}
		new->next = NULL;
	}
	return (new);
}

void	ft_lstaddfront(t_list **alst, t_list *new)
{
	t_list	*list;

	if (*alst == NULL)
		*alst = new;
	else
	{
		list = *alst;
		new->next = list;
		*alst = new;
	}
}

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list	*list;

	if (*alst == NULL)
		*alst = new;
	else
	{
		list = *alst;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
}

t_list	*ft_lstgetlast(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}
