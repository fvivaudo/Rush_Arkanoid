/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:13:48 by cchauvie          #+#    #+#             */
/*   Updated: 2013/11/27 15:07:37 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	index1;
	int	index2;

	index1 = 0;
	index2 = 0;
	while (s1[index1] != '\0' && s2[index2] != '\0')
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
