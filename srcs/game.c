/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:38:00 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/03 16:05:57 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>
#include <fcntl.h>
#include <unistd.h>

# include <math.h> //FORBIDDEN

static void	draw_brick(GLfloat x, GLfloat y)
{
	glBegin(GL_QUADS);
	glColor3f(2.f, 0.f, 0.f);
	glVertex2f(-1.f + y * BRICK_WIDTH, 1.f - x * BRICK_HEIGHT);
	glColor3f(0.f, 1.f, 0.f);
	glVertex2f(-0.85f + y * BRICK_WIDTH, 1.f - x * BRICK_HEIGHT);
	glColor3f(0.f, 0.f, 1.f);
	glVertex2f(-0.85f + y * BRICK_WIDTH, 0.9f - x * BRICK_HEIGHT);
	glColor3f(0.f, 0.f, 1.f);
	glVertex2f(-1.f + y * BRICK_WIDTH, 0.9f - x * BRICK_HEIGHT);
	glEnd();
}

static char	**get_map(char *name)
{
	char		**map;
	char		*buf;
	int			fd;
	int			y;

	if (! (map = (char **)malloc(sizeof(char *) * (MAP_HEIGHT + 1))))
		ft_do_error("Malloc");
	y = 0;
	if ((fd = open(name, O_RDONLY)) == (-1))
		ft_do_error("Can't open Map file !");
	while (get_next_line(fd, &buf))
	{
		ft_putendl(buf);
		map[y++] = ft_strdup(buf);
		free(buf);
	}
	map[y] = NULL;
	close(fd);
	return (map);
}

static char	**build_map(char **tmp_map)
{
	int			i;
	int			y;
	int			z;

	i = 0;
	y = 0;
	z = 0;
	while (tmp_map[y])
	{
		while (tmp_map[y][z])
		{
			if (ft_isdigit(tmp_map[y][z]))
				g_game.map[y][i] = ft_atoi(tmp_map[y] + z);
			while (ft_isdigit(tmp_map[y][z]))
				++z;
			++i;
			++z;
		}
		z = 0;
		i = 0;
		++y;
	}
	return (tmp_map);
}

void		update_map(char *name)
{
	static char	**tmp_map= NULL;
	int			i;
	int			y;

	if (!tmp_map)
		tmp_map = build_map(get_map(name));
	i = 0;
	y = 0;
	while (i < MAP_HEIGHT)
	{
		while (y < MAP_WIDTH)
		{
			if (g_game.map[i][y] == 1)
				draw_brick(i, y);
			++y;
		}
		y = 0;
		++i;
	}

	i = 0;
	y = 0;
	while (i < MAP_HEIGHT)
	{
		while (y < MAP_WIDTH)
		{
			ft_putnbr(g_game.map[i][y]);
			ft_putchar(' ');
			++y;
		}
		ft_putchar('\n');
		y = 0;
		++i;
	}
}

void		draw_bar(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.f, 0.f, 0.f);
	glBegin(GL_QUADS);
	glVertex2f(0.f + g_game.bar_position, -0.95f);
	glVertex2f(0.2f + g_game.bar_position, -0.95f);
	glVertex2f(0.2f + g_game.bar_position, -1.f);
	glVertex2f(0.f + g_game.bar_position, -1.f);
}

/*
 ** Define new position of the ball
 */
void		draw_ball(void)
{
	int			x;
	int			y;
	float		angle;
	double		rad;

	angle = 0.0f;
	rad = 0.02;
	glColor3f(1.0, 1.0, 0.6);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(g_game.y, g_game.x);
	while (angle < 2 * M_PI)
	{
		glVertex2f(g_game.y + sin(angle) * rad, g_game.x + cos(angle) * rad);
		angle += 0.2;
	}
/*
 ** colision and speed increase
 */

 x = fabs(g_game.x / BRICK_HEIGHT - 10);
 y = g_game.y / BRICK_WIDTH + 6;

 ft_printf("try = %d, %d\n", x, y);

 //printf("pos = %.0f, %.0f\n",  fabs(g_game.x / BRICK_HEIGHT - 10), g_game.y / BRICK_WIDTH + 6);
	if ((g_game.x + g_game.x_dir) >= 1 || (g_game.x + g_game.x_dir) <= -1 || g_game.map[x][y] == 1)
	{
		if (g_game.x_dir < 0.04 && g_game.x_dir > -0.04)
			g_game.x_dir *= -1.05;
		else
			g_game.x_dir *= -1;
	}
	if ((g_game.y + g_game.y_dir) >= 1 || (g_game.y + g_game.y_dir) <= -1)
	{
		if (g_game.y_dir < 0.04 && g_game.y_dir > -0.04 )
			g_game.y_dir *= -1.05;
		else
			g_game.y_dir *= -1;
	}
	if (g_game.map[x][y] == 1)
	{

		g_game.map[x][y] = 0;
	}
/*
 ** update pos
 */
	g_game.x += g_game.x_dir;
	g_game.y += g_game.y_dir;
 //printf("newpos = %.0f, %.0f\n",  fabs(g_game.x / BRICK_HEIGHT - 10), g_game.y / BRICK_WIDTH + 6);
	glEnd();
}
