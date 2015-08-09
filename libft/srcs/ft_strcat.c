/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:51:12 by cchauvie          #+#    #+#             */
/*   Updated: 2013/11/25 17:59:15 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	index;

	index = ft_strlen(s1);
	while (*s2 != '\0')
	{
		s1[index] = *s2;
		index++;
		s2++;
	}
	s1[index] = '\0';
	return (s1);
}
