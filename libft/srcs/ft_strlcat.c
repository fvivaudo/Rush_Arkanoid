/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:24:21 by cchauvie          #+#    #+#             */
/*   Updated: 2013/12/05 21:43:31 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	index;

	dst_size = (size < ft_strlen(dst) ? size : ft_strlen(dst));
	src_size = ft_strlen(src);
	index = ft_strlen(dst);
	if (size != 0)
	{
		while (index < size - 1 && *src != '\0')
		{
			dst[index] = *src;
			index++;
			src++;
		}
		dst[index] = '\0';
	}
	return (dst_size + src_size);
}
