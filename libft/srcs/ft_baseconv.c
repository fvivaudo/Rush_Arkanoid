/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baseconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 20:17:51 by cchauvie          #+#    #+#             */
/*   Updated: 2014/04/27 19:59:54 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_baseconv(unsigned long nbr, int base, int minlen)
{
	int		reste;
	char	nbr_save[100];
	int		index;
	size_t	count;

	index = 0;
	count = 0;
	if (nbr == 0)
		nbr_save[0] = 0;
	while (nbr > 0)
	{
		reste = nbr % base;
		nbr /= base;
		nbr_save[index] = (reste >= 0 && reste <= 9 ? reste + '0' : reste + 87);
		index++;
	}
	while (minlen - index > 0)
	{
		count += ft_putnbr(0);
		minlen--;
	}
	index--;
	while (index >= 0)
		count += ft_putchar(nbr_save[index--]);
	return (count);
}
