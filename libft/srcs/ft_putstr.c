/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 16:21:28 by cchauvie          #+#    #+#             */
/*   Updated: 2014/05/23 16:20:18 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putstr(char *s)
{
	size_t	index;

	if (!s)
		s = "(null)";
	index = ft_strlen(s);
	write(1, s, index);
	return (index);
}
