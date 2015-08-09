/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:49:39 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/03 23:31:23 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

void		draw_all(void)
{
	update_map(ft_strjoin("levels/level",
				ft_strjoin(ft_itoa(g_game.level), ".txt")));
	draw_infos();
	draw_bar();
	draw_ball();
}

void		draw_brick(float x, float y, int type)
{
	glBegin(GL_QUADS);
	if (type == 1)
		glColor3f(0.f, 0.f, 1.f);
	if (type == 2)
		glColor3f(2.f, 2.f, 0.f);
	if (type == 3)
		glColor3f(2.f, 0.5f, 0.f);
	if (type == 4)
		glColor3f(2.f, 2.f, 2.f);
	glVertex2f(-1.f + y * BRICK_WIDTH, 1.f - x * BRICK_HEIGHT);
	glVertex2f(-1.01f + (y + 1) * BRICK_WIDTH, 1.f - x * BRICK_HEIGHT);
	glVertex2f(-1.01f + (y + 1) * BRICK_WIDTH, 1.01f - (x + 1) * BRICK_HEIGHT);
	glVertex2f(-1.f + y * BRICK_WIDTH, 1.01f - (x + 1) * BRICK_HEIGHT);
	glEnd();
}

void		draw_infos(void)
{
	print_text(0.5, -0.7, ft_strjoin("Level = ", ft_itoa(g_game.level))
			, 0);
	print_text(0.5, -0.8, ft_strjoin("Life = ",
				ft_strjoin(ft_itoa(g_game.life), "/3")), 0);
	print_text(0.5, -0.9, ft_strjoin("Current Score = ",
				ft_itoa(g_game.score)), 0);
}

void		draw_bar(void)
{
	glColor3f(1.f, 0.f, 0.f);
	glBegin(GL_QUADS);
	glVertex2f(-0.1f + g_game.bar_position, -0.95f);
	glVertex2f(0.1f + g_game.bar_position, -0.95f);
	glVertex2f(0.1f + g_game.bar_position, -1.f);
	glVertex2f(-0.1f + g_game.bar_position, -1.f);
	glEnd();
}

void		draw_ball(void)
{
	int			x[2];
	int			y[2];
	int			collide;

	collide = 0;
	gen_ball();
	if (g_game.start && g_game.x > -1.000)
	{
		check_collide(x, y, &collide);
		check_bar();
		check_bit(collide);
		g_game.x += g_game.x_dir;
		g_game.y += g_game.y_dir;
	}
	else if (g_game.x <= -1)
		if_die();
	else
		g_game.y = g_game.bar_position;
	glEnd();
}
