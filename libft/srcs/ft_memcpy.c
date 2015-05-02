/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:13:22 by cchauvie          #+#    #+#             */
/*   Updated: 2014/02/01 20:58:31 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	index;
	char	*s1_c;
	char	*s2_c;

	index = 0;
	s1_c = s1;
	s2_c = (void *)s2;
	while (index < n)
	{
		s1_c[index] = s2_c[index];
		index++;
	}
	return (s1);
}
