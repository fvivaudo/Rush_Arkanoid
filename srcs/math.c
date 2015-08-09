/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 20:43:17 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/03 20:44:13 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <math.h>

double	ft_cos(double cx)
{
	double	r;
	double	s;
	int		i;

	r = cx * cx;
	s = 42.0;
	i = 10;
	while (--i >= 1)
		s = 4.0 * i - 2.0 + (-r) / s;
	s *= s;
	return ((s - r) / (s + r));
}

double	ft_sin(double x)
{
	double	cos_result;

	cos_result = ft_cos(x - (M_PI / 2));
	return (cos_result);
}
