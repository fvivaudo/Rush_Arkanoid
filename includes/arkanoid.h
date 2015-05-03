/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 12:23:41 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/03 22:52:21 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include "libft.h"
# include <stdlib.h>

# define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

/*
** Define global variables
*/

# define WINDOW_NAME "Super Arkanoid"
# define DEFAULT_WIDTH (1000)
# define DEFAULT_HEIGHT (1000)
# define MAP_WIDTH (12)
# define MAP_HEIGHT (20)
# define BRICK_WIDTH (2.f / MAP_WIDTH)
# define BRICK_HEIGHT (2.f / MAP_HEIGHT)

/*
** Global Game stuct variables
*/

typedef struct	s_game
{
	int		**map;
	int		level;
	int		life;
	int		score;
	int		target_score;
	int		start_level;
	bool	start;
	bool	pause;
	bool	win;
	double	bar_position;
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
** loadmap.c
*/

void			g_var_reset(void);
void			g_var_init(void);
void			check_map_file(char *filename);

/*
** window.c
*/

void			print_text(float x, float y, char *str, bool big);
int				init_game(void);

/*
** game.c
*/

void			update_map(char *name);

/*
** draw.c
*/

void			draw_brick(float x, float y, int type);
void			draw_infos(void);
void			draw_bar(void);
void			draw_ball(void);

/*
** math.c
*/

double			ft_cos(double cx);
double			ft_sin(double x);

#endif
