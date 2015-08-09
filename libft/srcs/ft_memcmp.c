/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 17:57:30 by cchauvie          #+#    #+#             */
/*   Updated: 2014/01/18 19:22:40 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;
	const unsigned char	*s1_copy;
	const unsigned char	*s2_copy;

	index = 0;
	s1_copy = (const unsigned char*)s1;
	s2_copy = (const unsigned char*)s2;
	while (index < n)
	{
		if (*s1_copy != *s2_copy)
			return (*s1_copy - *s2_copy);
		index++;
		s1_copy++;
		s2_copy++;
	}
	return (0);
}
