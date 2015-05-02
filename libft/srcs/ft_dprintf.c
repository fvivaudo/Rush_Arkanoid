/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 17:55:48 by cchauvie          #+#    #+#             */
/*   Updated: 2014/02/01 17:55:54 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int	ft_args_switch(int fd, const char *str, size_t *i, va_list ap)
{
	if (str[*i] == 's')
		return (ft_putstr_fd(va_arg(ap, char*), fd) - 1);
	else if (str[*i] == 'c')
		return (ft_putchar_fd(va_arg(ap, int), fd) - 1);
	else if (str[*i] == '%')
		return (ft_putchar_fd('%', fd) - 1);
	else if (str[*i] == 'd' || str[*i] == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), fd) - 1);
	else if (str[*i] == 'u')
		return (ft_putnbr_fd(va_arg(ap, unsigned int), fd) - 1);
	else
		return (0);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	size_t	index;
	size_t	rval;

	va_start(ap, format);
	index = 0;
	rval = 0;
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			rval += ft_args_switch(fd, format, &index, ap);
		}
		else
			ft_putchar_fd(format[index], fd);
		index++;
		rval++;
	}
	va_end(ap);
	return (rval);
}
