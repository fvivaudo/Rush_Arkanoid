/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:17:13 by cchauvie          #+#    #+#             */
/*   Updated: 2014/01/31 19:06:20 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s_copy;
	int		index;

	s_copy = ft_strnew(len + 1);
	if (!s_copy || start > ft_strlen(s) || start + len > ft_strlen(s))
		return (NULL);
	index = 0;
	while (len > 0)
	{
		s_copy[index] = s[start];
		index++;
		start++;
		len--;
	}
	s_copy[index] = '\0';
	return (s_copy);
}
