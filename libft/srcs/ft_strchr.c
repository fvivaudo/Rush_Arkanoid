/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:39:20 by cchauvie          #+#    #+#             */
/*   Updated: 2013/12/01 20:50:59 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;
	int	length;

	index = 0;
	length = ft_strlen(s) + 1;
	while (index < length)
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
		index++;
	}
	return (NULL);
}
