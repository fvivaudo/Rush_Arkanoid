/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 20:00:56 by cchauvie          #+#    #+#             */
/*   Updated: 2014/01/31 19:06:43 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s_out;
	size_t	index;

	s_out = ft_strnew(1 + n);
	index = 0;
	if (!s_out)
		return (NULL);
	while (s1[index] != '\0' && index < n)
	{
		s_out[index] = s1[index];
		index++;
	}
	s_out[index] = '\0';
	return (s_out);
}
