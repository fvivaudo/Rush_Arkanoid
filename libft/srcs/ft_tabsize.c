/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 17:21:26 by cchauvie          #+#    #+#             */
/*   Updated: 2014/01/14 17:21:56 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabsize(char **tab)
{
	int	count;

	count = 0;
	while (*tab != NULL)
	{
		count++;
		tab++;
	}
	return (count);
}
