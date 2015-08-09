/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:00:41 by cchauvie          #+#    #+#             */
/*   Updated: 2014/02/01 20:58:04 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*position;

	position = NULL;
	while (*s)
	{
		if (*s == (char)c)
			position = (char *)s;
		s++;
	}
	return ((*s == (char)c ? (char *)s : position));
}
