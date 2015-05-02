/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 14:25:35 by cchauvie          #+#    #+#             */
/*   Updated: 2014/03/23 18:52:36 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list *begin, void (*f)(void *))
{
	t_list	*next;

	while (begin != NULL)
	{
		next = begin->next;
		if (f != NULL)
			f(begin->content);
		free(begin);
		begin = next;
	}
}

size_t	ft_lstsize(t_list *alst)
{
	size_t	size;

	size = 0;
	while (alst)
	{
		size++;
		alst = alst->next;
	}
	return (size);
}

void	ft_lstprint(t_list *list)
{
	while (list != NULL)
	{
		ft_putendl((char *)list->content);
		list = list->next;
	}
}
