/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:55:57 by cchauvie          #+#    #+#             */
/*   Updated: 2014/05/23 16:21:50 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(long n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n *= -1;
		index++;
	}
	while (n)
	{
		n /= 10;
		index++;
	}
	return (index);
}
