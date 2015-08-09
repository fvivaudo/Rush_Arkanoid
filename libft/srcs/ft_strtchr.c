/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 17:00:17 by cchauvie          #+#    #+#             */
/*   Updated: 2014/02/13 15:22:25 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
			break ;
		index++;
	}
	if (index < ft_strlen(s))
		return (ft_strndup(s, index));
	return ((char *)s);
}
