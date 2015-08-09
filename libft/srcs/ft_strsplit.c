/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:18:55 by cchauvie          #+#    #+#             */
/*   Updated: 2014/03/25 18:58:53 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strsepc(const char *s, const char c)
{
	int		count;
	char	save;

	count = 0;
	save = '\0';
	while (*s != '\0')
	{
		if (*s == c)
			save = '\0';
		if (*s != c && save == '\0')
		{
			save = c;
			count++;
		}
		s++;
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**s_out;
	int		index_tab;
	int		index1;
	int		index2;

	if (!s)
		return (NULL);
	s_out = (char**)ft_memalloc(ft_strsepc(s, c) + 1);
	index1 = 0;
	index2 = 0;
	index_tab = 0;
	while (s[index1] != '\0')
	{
		while (s[index1] == c)
			index1++;
		index2 = index1;
		while (s[index1] != c && s[index1] != '\0')
			index1++;
		if (index1 > index2)
			s_out[index_tab++] = ft_strsub(s, index2, (index1 - index2));
	}
	s_out[index_tab] = NULL;
	return (s_out);
}
