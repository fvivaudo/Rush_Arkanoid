/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:18:28 by cchauvie          #+#    #+#             */
/*   Updated: 2014/05/23 16:15:47 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	len;
	char	*s_out;

	while (*s && ft_isspace(*s))
		s++;
	len = ft_strlen(s) - 1;
	while (*s && ft_isspace(s[len]))
		len--;
	if (!(s_out = ft_strnew(len + 1)))
		return (NULL);
	s_out = ft_strndup(s, ++len);
	s_out[++len] = '\0';
	return (s_out);
}
