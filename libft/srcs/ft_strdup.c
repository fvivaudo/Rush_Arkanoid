/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:35:23 by cchauvie          #+#    #+#             */
/*   Updated: 2014/01/31 19:07:26 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s_dump;
	int		index;

	s_dump = ft_strnew(1 + ft_strlen(s1));
	index = 0;
	if (!s_dump)
		return (NULL);
	while (s1[index] != '\0')
	{
		s_dump[index] = s1[index];
		index++;
	}
	s_dump[index] = '\0';
	return (s_dump);
}
