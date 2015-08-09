/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:01:36 by cchauvie          #+#    #+#             */
/*   Updated: 2013/11/27 15:15:13 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	while (s1[index1] != '\0' && s2[index2] != '\0' && index1 < n)
	{
		if (s1[index1] == s2[index2])
			index2++;
		else if (s1[index1] != s2[index2] && index2 != 0)
		{
			index1 -= index2 - 1;
			index2 = 0;
			continue ;
		}
		index1++;
	}
	if (s2[index2] == '\0')
		return ((char *)s1 + (index1 -= index2));
	return (NULL);
}
