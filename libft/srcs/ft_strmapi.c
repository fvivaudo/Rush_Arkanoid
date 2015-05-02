/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:14:47 by cchauvie          #+#    #+#             */
/*   Updated: 2014/01/31 19:07:02 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_out;
	unsigned int	index;

	index = 0;
	s_out = ft_strnew(ft_strlen(s) + 1);
	while (*s != '\0')
	{
		s_out[index] = (*f)(index, *s);
		index++;
		s++;
	}
	s_out[index] = '\0';
	return (s_out);
}
