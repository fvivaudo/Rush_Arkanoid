/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:16:38 by cchauvie          #+#    #+#             */
/*   Updated: 2014/01/31 19:42:15 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*p_s1;
	const unsigned char	*p_s2;

	p_s2 = s2;
	if (!n)
		return (s1);
	p_s1 = s1;
	if (p_s2 < p_s1)
	{
		p_s1 += n;
		p_s2 += n;
		while (n--)
			*--p_s1 = *--p_s2;
	}
	else
		while (n--)
			*p_s1++ = *p_s2++;
	return (s1);
}
