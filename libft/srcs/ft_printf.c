/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 14:26:31 by cchauvie          #+#    #+#             */
/*   Updated: 2014/04/26 20:22:29 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int	ft_args_switch(const char *str, size_t *i, va_list ap)
{
	while (ft_isdigit(str[*i]))
	{
		i++;
	}
	if (str[*i] == 's')
		return (ft_putstr(va_arg(ap, char*)) - 1);
	else if (str[*i] == 'c')
		return (ft_putchar(va_arg(ap, int)) - 1);
	else if (str[*i] == '%')
		return (ft_putchar('%') - 1);
	else if (str[*i] == 'd' || str[*i] == 'i')
		return (ft_putnbr(va_arg(ap, int)) - 1);
	else if (str[*i] == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int)) - 1);
	else if (str[*i] == 'o')
		return (ft_baseconv(va_arg(ap, unsigned int), 8, 0) - 1);
	else if (str[*i] == 'x')
		return (ft_baseconv(va_arg(ap, unsigned int), 16, 0) - 1);
	else if (str[*i] == 'p')
	{
		ft_putstr("0x");
		return (2 + ft_baseconv(va_arg(ap, unsigned long), 16, 0) - 1);
	}
	else
		return (0);
}

int			ft_printf(const char *format, ...)
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
			rval += ft_args_switch(format, &index, ap);
		}
		else
			ft_putchar(format[index]);
		index++;
		rval++;
	}
	va_end(ap);
	return (rval);
}
