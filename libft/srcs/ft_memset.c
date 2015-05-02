/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:11:32 by cchauvie          #+#    #+#             */
/*   Updated: 2013/12/05 22:03:17 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*b_out;

	index = 0;
	b_out = (unsigned char*)b;
	while (index < len)
	{
		b_out[index] = (unsigned char)c;
		index++;
	}
	return (b);
}
