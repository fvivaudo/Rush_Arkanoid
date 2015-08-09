/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:37:48 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/03 22:39:16 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void	print_game_cmd(void)
{
	ft_printf("=============================\n\
Game Commands :\n\
- ESC : Exit game\n\
- Space : Pause\n\
- Enter : Start game\n\
- Left Arrow : Go left\n\
- Right Arrow : Go right\n\
=============================\n");
}

void		ft_do_error(char *str)
{
	ft_dprintf(2, "ERROR : %s\n", str);
	exit(EXIT_FAILURE);
}

int			main(void)
{
	check_map_file("levels/level0.txt");
	g_var_init();
	print_game_cmd();
	return (init_game());
}
