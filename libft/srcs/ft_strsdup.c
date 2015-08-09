/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 20:00:17 by cchauvie          #+#    #+#             */
/*   Updated: 2014/01/31 19:11:25 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsdup(const char *s1, size_t start)
{
	char	*strdup;
	int		index;

	strdup = ft_strnew(1 + (ft_strlen(s1) - start));
	index = 0;
	if (!strdup)
		return (NULL);
	while (s1[start] != '\0')
	{
		strdup[index] = s1[start];
		index++;
		start++;
	}
	strdup[index] = '\0';
	return (strdup);
}
