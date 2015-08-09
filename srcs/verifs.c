/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 23:09:51 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/03 23:30:51 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>
#include <math.h>

void		if_die(void)
{
	g_game.life--;
	if (g_game.life == 0)
	{
		print_text(-0.08, 0, "GAME OVER !!", 1);
		draw_infos();
		g_game.stop = 1;
	}
	else
	{
		g_game.start = 0;
		g_game.x = -0.93;
		g_game.x_dir = 0.01;
		g_game.y_dir = 0;
	}
}

void		gen_ball(void)
{
	float		angle;

	angle = 0.0f;
	glColor3f(1.0, 1.0, 0.6);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(g_game.y, g_game.x);
	while (angle < 2 * M_PI)
	{
		glVertex2f(g_game.y + ft_sin(angle) * 0.02,
				g_game.x + ft_cos(angle) * 0.02);
		angle += 0.2;
	}
	glEnd();
}

void		check_collide(int *x, int *y, int *collide)
{
	x[0] = fabs(g_game.x / BRICK_HEIGHT - 10);
	y[0] = g_game.y / BRICK_WIDTH + 6;
	x[1] = fabs((g_game.x + g_game.x_dir) / BRICK_HEIGHT - 10);
	y[1] = (g_game.y + g_game.y_dir) / BRICK_WIDTH + 6;
	if ((g_game.x + g_game.x_dir) < 1
			&& (g_game.x + g_game.x_dir) > -1
			&& (g_game.y + g_game.y_dir) < 1 && (g_game.y + g_game.y_dir) > -1)
		if (g_game.map[x[1]][y[1]] != 0)
		{
			if (g_game.map[x[1]][y[0]] != 0)
				*collide += 1;
			if (g_game.map[x[0]][y[1]] != 0)
				*collide += 2;
			if (g_game.map[x[1]][y[1]] < 4)
			{
				--g_game.map[x[1]][y[1]];
				g_game.score += 1;
				--g_game.target_score;
			}
		}
}

void		check_bit(int collide)
{
	if ((g_game.x + g_game.x_dir) >= 1 || CHECK_BIT(collide, 0))
	{
		if (g_game.x_dir > 0 && g_game.x_dir < 0.04)
			g_game.x_dir += 0.0001;
		else if (g_game.x_dir < 0 && g_game.x_dir > -0.04)
			g_game.x_dir -= 0.0001;
		g_game.x_dir *= -1;
	}
	if ((g_game.y + g_game.y_dir) >= 1
			|| (g_game.y + g_game.y_dir) <= -1 || CHECK_BIT(collide, 1))
	{
		if (g_game.y_dir > 0 && g_game.y_dir < 0.04)
			g_game.y_dir += 0.0001;
		else if (g_game.y_dir < 0 && g_game.y_dir > -0.04)
			g_game.y_dir -= 0.0001;
		g_game.y_dir *= -1;
	}
}

void		check_bar(void)
{
	if (g_game.x < -0.93)
	{
		if ((g_game.y < (g_game.bar_position + 0.1))
				&& (g_game.y > (g_game.bar_position - 0.1)))
		{
			g_game.y_dir -= (g_game.bar_position - g_game.y) / 10;
			g_game.x_dir *= -1;
		}
	}
}
