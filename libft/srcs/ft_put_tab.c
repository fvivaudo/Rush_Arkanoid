/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 20:20:19 by cchauvie          #+#    #+#             */
/*   Updated: 2013/12/27 20:20:29 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_put_tab(char **tab)
{
	size_t	index;

	index = 0;
	while (tab[index] != NULL)
	{
		ft_putendl(tab[index]);
		index++;
	}
	return (index);
}
