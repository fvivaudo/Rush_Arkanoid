/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 12:23:41 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/02 20:10:06 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include "libft.h"
# include <stdlib.h>

/*
 ** Define global variables
 */

# define WINDOW_NAME "Super Arkanoid"
# define DEFAULT_WIDTH (640)
# define DEFAULT_HEIGHT (480)
# define MAP_WIDTH (12)
# define MAP_HEIGHT (20)

/*
 ** Global Game stuct variables
 */

typedef struct	s_game
{
	int		level;
	double	bar_position;
	double	speed;

	double	x;
	double	y;
	double	x_dir;
	double	y_dir;
}				t_game;

t_game	g_game;

/*
** window.c
*/

int		init_game(void);

/*
** game.c
*/

void	build_map(char *name);
void	drawball(void);

#endif
