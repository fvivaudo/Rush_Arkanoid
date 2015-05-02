/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:17:56 by cchauvie          #+#    #+#             */
/*   Updated: 2014/03/14 18:36:43 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	char	*s_out;

	index = 0;
	s_out = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s_out)
		return (NULL);
	while (s1 && *s1 != '\0')
	{
		s_out[index] = *s1;
		s1++;
		index++;
	}
	while (s2 && *s2 != '\0')
	{
		s_out[index] = *s2;
		s2++;
		index++;
	}
	s_out[index] = '\0';
	return (s_out);
}
