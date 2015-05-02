/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:17:33 by cchauvie          #+#    #+#             */
/*   Updated: 2013/12/05 21:38:57 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_c;
	size_t			index;

	s_c = (unsigned char*)s;
	index = 0;
	while (s != NULL && index < n)
	{
		if (s_c[index] == (unsigned char)c)
			return (s_c + index);
		index++;
	}
	return (NULL);
}
