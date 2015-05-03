/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 12:23:41 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/03 16:03:56 by cchauvie         ###   ########.fr       */
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
# define DEFAULT_WIDTH (480)
# define DEFAULT_HEIGHT (480)
# define MAP_WIDTH (12)
# define MAP_HEIGHT (20)
# define BRICK_WIDTH (0.15)
# define BRICK_HEIGHT (0.1)

/*
** Global Game stuct variables
*/

typedef struct	s_game
{
	int		**map;
	int		level;
	bool	pause;
	double	bar_position;
	double	speed;

	double	x;
	double	y;
	double	x_dir;
	double	y_dir;
}				t_game;

t_game			g_game;

/*
** main.c
*/

void			ft_do_error(char *str);

/*
** window.c
*/

int				init_game(void);

/*
** game.c
*/

void			update_map(char *name);
void			draw_bar(void);
void			draw_ball(void);

#endif
