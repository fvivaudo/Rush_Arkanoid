/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 19:20:33 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/02 20:55:08 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>
#include <unistd.h>

static void	error_callback(int error, const char *description)
{
	(void)error;
	ft_dprintf(2, "%s\n", description);
}

static void	key_callback(GLFWwindow *window,
		int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (action == GLFW_PRESS && key == GLFW_KEY_SPACE)
		g_game.pause = !g_game.pause;
	if ((action == GLFW_PRESS || action == GLFW_REPEAT) && !g_game.pause)
	{
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(window, GL_TRUE);
		else if (key == GLFW_KEY_RIGHT && g_game.bar_position <= 1.0)
			g_game.bar_position += 0.03;
		else if (key == GLFW_KEY_LEFT && g_game.bar_position >= -1.0)
			g_game.bar_position -= 0.03;
	}
}

static void	run_game(GLFWwindow *window)
{
	int			width;
	int			height;
	float		ratio;
	int			i;

	ft_bzero(&g_game, sizeof(t_game));
	i = 0;
	g_game.level = 0;
	g_game.bar_position = 0;
	g_game.speed = 1.3;
	g_game.x = -0.95;
	g_game.y = 0;
	g_game.x_dir = 0.01;
	g_game.y_dir = 0.01;
	g_game.map = (int**)malloc(sizeof(int *) * (MAP_HEIGHT));
	while (i < 20)
	{
		g_game.map[i] = (int *)malloc(sizeof(int) * MAP_WIDTH);
		++i;
	}
	while (!glfwWindowShouldClose(window))
	{
		if (!g_game.pause)
		{
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float) height;

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);

		glColor3f(1.f, 0.f, 0.f);
		glBegin(GL_QUADS);
		glVertex2f(0.f + g_game.bar_position, -0.95f);
		glVertex2f(0.2f + g_game.bar_position, -0.95f);
		glVertex2f(0.2f + g_game.bar_position, -1.f);
		glVertex2f(0.f + g_game.bar_position, -1.f);
		update_map("levels/level0.txt");
		drawball();

		glfwSwapBuffers(window);
	}
		glfwPollEvents();
	
	}
}

int			init_game(void)
{
	GLFWwindow	*window;

	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return (EXIT_FAILURE);
	window = glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT, WINDOW_NAME,
			NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return (EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	run_game(window);
	glfwDestroyWindow(window);
	glfwTerminate();
	return (EXIT_SUCCESS);
}
