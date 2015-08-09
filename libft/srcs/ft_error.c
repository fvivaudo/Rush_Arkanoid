/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 19:07:08 by cchauvie          #+#    #+#             */
/*   Updated: 2014/05/16 16:35:06 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strerror(int errnum)
{
	if (errnum < 0 && errnum > ELAST)
		return (NULL);
	return ((char *)sys_errlist[errnum]);
}

void	ft_perror(char *s)
{
	if (s && *s != '\0')
		ft_dprintf(2, "%s: ", s);
	ft_dprintf(2, "%s\n", ft_strerror(errno));
}
