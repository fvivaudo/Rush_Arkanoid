/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:21:52 by cchauvie          #+#    #+#             */
/*   Updated: 2014/05/23 16:18:02 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	index;

	if (!s)
		s = "(null)";
	index = ft_strlen(s);
	write(fd, s, index);
	return (index);
}
