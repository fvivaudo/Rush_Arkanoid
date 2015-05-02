/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 17:07:58 by cchauvie          #+#    #+#             */
/*   Updated: 2014/01/31 19:16:17 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*result;
	size_t	index;

	result = ft_strnew(ft_numlen(n) + 1);
	index = 0;
	if (result)
	{
		if (n == 0)
			result[index++] = '0';
		else if (n < 0)
		{
			n *= -1;
			result[index++] = '-';
		}
		while (n)
		{
			result[index++] = n % 10 + '0';
			n /= 10;
		}
		result[index] = '\0';
	}
	return (result);
}
