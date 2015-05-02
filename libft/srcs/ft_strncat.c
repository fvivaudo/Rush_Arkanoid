/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:14:21 by cchauvie          #+#    #+#             */
/*   Updated: 2013/11/25 17:59:45 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	index;
	unsigned int	index2;

	index = ft_strlen(s1);
	index2 = 0;
	while (s2[index2] != '\0' && index2 < n)
	{
		s1[index] = s2[index2];
		index++;
		index2++;
	}
	s1[index] = '\0';
	return (s1);
}
