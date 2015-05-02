/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:14:17 by cchauvie          #+#    #+#             */
/*   Updated: 2014/01/31 19:13:56 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s_new;
	int		index;

	index = 0;
	s_new = ft_strnew(ft_strlen(s) + 1);
	while (*s != '\0')
	{
		s_new[index] = (*f)(*s);
		s++;
		index++;
	}
	s_new[index] = '\0';
	return (s_new);
}
