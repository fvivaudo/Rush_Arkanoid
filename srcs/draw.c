/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:49:39 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/03 22:53:57 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

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

# include <stdio.h> //FORBIDDEN
void		draw_ball(void)
{
	int			x;
	int			y;
	int			collide;
	int			x_d;
	int			y_d;
	float		angle;
	double		rad;

	collide = 0;
	angle = 0.0f;
	rad = 0.02;
	glColor3f(1.0, 1.0, 0.6);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(g_game.y, g_game.x);
	while (angle < 2 * M_PI)
	{
		glVertex2f(g_game.y + ft_sin(angle) * rad, g_game.x + ft_cos(angle) * rad);
		angle += 0.2;
	}
	glEnd();
	//printf("%g\n", g_game.x);
	if (g_game.start && g_game.x > -1.000)
	{

		/*
		 ** colision and speed increase
		 */

		x = fabs(g_game.x / BRICK_HEIGHT - 10);
		y = g_game.y / BRICK_WIDTH + 6;

		x_d = fabs((g_game.x + g_game.x_dir) / BRICK_HEIGHT - 10);
		y_d = (g_game.y + g_game.y_dir) / BRICK_WIDTH + 6;
		// printf("try: x=%d, y=%d, game.x_dir=%f, game.y_dir=%f, game.x=%f, game.y=%f\n", x, y, g_game.x_dir, g_game.y_dir, g_game.x, g_game.y);
		//printf("pos = %.0f, %.0f\n",  fabs(g_game.x / BRICK_HEIGHT - 10), g_game.y / BRICK_WIDTH + 6);
		//	if (g_game.map[x_d][y_d] == 1)
		//{
		//	g_game.map[x][y] = 0;
		//}
		if ((g_game.x + g_game.x_dir) < 1 && (g_game.x + g_game.x_dir) > -1 && (g_game.y + g_game.y_dir) < 1 && (g_game.y + g_game.y_dir) > -1)
		{
			if (g_game.map[x_d][y_d] != 0)
			{
				if (g_game.map[x_d][y] != 0)
				{
					ft_putendl("Ok1");
					collide += 1;
				}
				if (g_game.map[x][y_d] != 0)
				{
					ft_putendl("Ok2");
					collide += 2;
				}
				if (g_game.map[x_d][y_d] < 4)
				{
					--g_game.map[x_d][y_d] ;
					g_game.score += 1;
					--g_game.target_score;
				}
				ft_putendl("Ok3");
			}
		}
		if (g_game.x < -0.93)
		{
			if ((g_game.y < (g_game.bar_position + 0.1)) && (g_game.y > (g_game.bar_position - 0.1)))
			{
				printf("change into = %g\n", g_game.bar_position - g_game.y);
				g_game.y_dir -= (g_game.bar_position - g_game.y) / 10;
				g_game.x_dir *= -1;
			}
		}
		if ((g_game.x + g_game.x_dir) >= 1 || CHECK_BIT(collide, 0))
		{
			ft_putendl("boing");
			if (g_game.x_dir > 0 && g_game.x_dir < 0.04)
				g_game.x_dir += 0.0001;
			else if (g_game.x_dir < 0 && g_game.x_dir > -0.04)
				g_game.x_dir -= 0.0001;
			g_game.x_dir *= -1;
		}
		if ((g_game.y + g_game.y_dir) >= 1 || (g_game.y + g_game.y_dir) <= -1 || CHECK_BIT(collide, 1))
		{
			if (g_game.y_dir > 0 && g_game.y_dir < 0.04)
				g_game.y_dir += 0.0001;
			else if (g_game.y_dir < 0 && g_game.y_dir > -0.04)
				g_game.y_dir -= 0.0001;
			g_game.y_dir *= -1;
		}
		g_game.x += g_game.x_dir;
		g_game.y += g_game.y_dir;
	}
	else if (g_game.x <= -1)
	{
		g_game.life--;
		if (g_game.life == 0)
			exit(0);
		else
		{
			g_game.start = 0;
			g_game.x = -0.93;
			g_game.x_dir = 0.01;
			g_game.y_dir = 0;
		}
	}
	else
		g_game.y = g_game.bar_position;
	/*
	 ** update pos
	 */

	//printf("newpos = %.0f, %.0f\n",  fabs(g_game.x / BRICK_HEIGHT - 10), g_game.y / BRICK_WIDTH + 6);
	glEnd();
}
