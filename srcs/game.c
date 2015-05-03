/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:38:00 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/02 20:42:26 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

static void	brick(GLfloat x, GLfloat y)
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

	map = (char**)malloc(sizeof(char *) * 21);
	y = 0;
	if ((fd = open(name, O_RDONLY)) == (-1))
	{
		ft_dprintf(2, "ERROR : Can't open Map file\n");
		exit(0);
	}
	while (get_next_line(fd, &buf))
	{
		ft_putendl(buf);
		map[y] = ft_strdup(buf);
		++y;
		free(buf);
	}
	map[y] = NULL;
	close(fd);
	return (map);
}
char	**build_map(char **tmp_map)
{
	int			i;
	int			y;
	int			z;
	//char		**tmp_map;

	i = 0;
	y = 0;
	z = 0;
	while (tmp_map[y])
	{
		while (tmp_map[y][z])
		{
			if (ft_isdigit(tmp_map[y][z]))
			{
				g_game.map[y][i] = ft_atoi(tmp_map[y] + z);
			}
			while (ft_isdigit(tmp_map[y][z]))
				++z;
			++i;
			++z;
		}
		if (i != MAP_WIDTH)
		{
			ft_putnbr(i);
			ft_dprintf(2, "ERROR : Map file content width must be = %d\n", MAP_WIDTH);
			exit(EXIT_FAILURE);
		}
		z = 0;
		i = 0;
		++y;
	}







	if (y != MAP_HEIGHT)
	{
		ft_putnbr(y);
		ft_dprintf(2, "ERROR : Map file content height must be = %d\n", MAP_HEIGHT);
		exit(EXIT_FAILURE);
	}

	return (tmp_map);
}

void		update_map(char *name)
{
	static char	**tmp_map= NULL;
	int			i;
	int			y;
	//char		**tmp_map;
	if (!tmp_map)
	{
		tmp_map = build_map(get_map(name));
	}
	i = 0;
	y = 0;
	while (i < MAP_HEIGHT)
	{
		while (y < MAP_WIDTH)
		{
			if (g_game.map[i][y] == 1)
				brick(i, y);
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
/*
 ** Define new position of the ball
 */

void		drawball(void)
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

 printf("try = %d, %d\n", x, y);

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
