/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:37:48 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/02 16:15:09 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int		main(void)
{
	ft_printf("Game Commands :\n\
- ESC : Exit game\n\
- Space : Pause\n\
- Left Arrow : Go left\n\
- Right Arrow : Go right\n\
=============================\n");
	return (init_game());
}
