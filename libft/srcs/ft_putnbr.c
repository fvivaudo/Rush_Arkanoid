/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:02:16 by cchauvie          #+#    #+#             */
/*   Updated: 2014/03/25 18:32:34 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_writenbr(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n *= -1);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

size_t		ft_putnbr(long n)
{
	size_t	index;

	index = ft_numlen(n);
	ft_writenbr(n);
	return (index);
}
