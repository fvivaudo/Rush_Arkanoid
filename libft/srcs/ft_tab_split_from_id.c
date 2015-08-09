/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_split_from_id.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 20:30:59 by cchauvie          #+#    #+#             */
/*   Updated: 2014/01/31 19:31:17 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tab_split_from_id(char **tab, int pos)
{
	char	**tab_out;
	int		index;

	tab_out = (char**)ft_memalloc(ft_tabsize(tab) + 1);
	index = 0;
	while (pos <= ft_tabsize(tab))
		tab_out[index++] = tab[pos++];
	tab_out[index] = NULL;
	return (tab_out);
}
