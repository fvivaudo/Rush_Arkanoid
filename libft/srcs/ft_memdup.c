/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 18:31:03 by cchauvie          #+#    #+#             */
/*   Updated: 2014/02/22 18:31:05 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *s, size_t size)
{
	void	*s_dup;

	s_dup = ft_memalloc(size);
	if (s_dup != NULL)
		s_dup = ft_memcpy(s_dup, s, size);
	return (s_dup);
}
