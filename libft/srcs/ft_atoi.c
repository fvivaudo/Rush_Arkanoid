/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 17:57:00 by cchauvie          #+#    #+#             */
/*   Updated: 2014/06/21 02:57:44 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	rst;
	int	sign;

	rst = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = (*str == '-' ? -1 : 1);
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		rst *= 10;
		rst += *str - '0';
		str++;
	}
	return (rst * sign);
}
