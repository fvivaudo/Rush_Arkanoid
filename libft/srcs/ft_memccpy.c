/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:15:25 by cchauvie          #+#    #+#             */
/*   Updated: 2015/03/12 16:53:38 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*s1_c;
	char	*s2_c;
	size_t	index;

	s1_c = s1;
	s2_c = (void *)s2;
	index = 0;
	while (index < n)
	{
		s1_c[index] = s2_c[index];
		if (s1_c[index] == (unsigned char)c)
			return (s1 + index + 1);
		index++;
	}
	return (NULL);
}
