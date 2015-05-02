/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 21:30:18 by cchauvie          #+#    #+#             */
/*   Updated: 2015/04/09 18:42:37 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void		*new;

	if (!ptr)
		return (ft_memalloc(new_size));
	new = ft_memalloc(new_size);
	if (new)
	{
		new = ft_memcpy(new, ptr, new_size);
		free(ptr);
	}
	return (new);
}
