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

static void	brick(GLfloat x, GLfloat y)
{
	glBegin(GL_QUADS);
	glColor3f(2.f, 0.f, 0.f);
	glVertex2f(-1.f + x * 0.15, 1.f - y * 0.1);
	glColor3f(0.f, 1.f, 0.f);
	glVertex2f(-0.85f + x * 0.15, 1.f - y * 0.1);
	glColor3f(0.f, 0.f, 1.f);
	glVertex2f(-0.85f + x * 0.15, 0.9f - y * 0.1);
	glColor3f(0.f, 0.f, 1.f);
	glVertex2f(-1.f + x * 0.15, 0.9f - y * 0.1);
	glEnd();
}

static char	**get_map(char *name)
{
	char		*buf;
	char		**map;
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
	return (map);
}

void		build_map(char *name)
{
	static char	**map = NULL;
	int			i;
	int			y;
	int			z;

	if (!map)
		map = get_map(name);
	i = 0;
	y = 0;
	z = 0;
	while (map[y])
	{
		while (map[y][z])
		{
			if (ft_isdigit(map[y][z]) && ft_atoi(map[y] + z) != 0)
				brick(i, y);
			while (ft_isdigit(map[y][z]))
				++z;
			++i;
			++z;
		}
		if (i != MAP_WIDTH)
		{
			ft_dprintf(2, "ERROR : Map file content width must be = %d\n", MAP_WIDTH);
			exit(EXIT_FAILURE);
		}
		z = 0;
		i = 0;
		++y;
	}
	if (y != MAP_HEIGHT)
	{
		ft_dprintf(2, "ERROR : Map file content height must be = %d\n", MAP_HEIGHT);
		exit(EXIT_FAILURE);
	}
}

void		drawball(void)
{
	float		x;
	float		y;
	float		angle;
	double		radius;

	angle = 0.0f;
	radius = 0.02;
	glColor3f(1.0, 1.0, 0.6);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(g_game.x, g_game.y);
	while (angle < 2 * M_PI)
	{
		x = g_game.x + sin(angle) * radius;
		y = g_game.y + cos(angle) * radius;
		glVertex2f(x, y);
		angle += 0.2;
	}
	g_game.x += 0.001;
	g_game.y += 0.001;
	glEnd();
}
