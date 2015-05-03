/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 19:20:33 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/03 16:06:33 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>

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
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(window, GL_TRUE);
		else if (key == GLFW_KEY_SPACE)
			g_game.pause = !g_game.pause;
		else if (!g_game.pause
				&& key == GLFW_KEY_RIGHT && g_game.bar_position + 0.2 <= 1.0)
			g_game.bar_position += 0.03;
		else if (!g_game.pause &&
				key == GLFW_KEY_LEFT && g_game.bar_position >= -1.0)
			g_game.bar_position -= 0.03;
	}
}

static void	run_game(GLFWwindow *window)
{
	int			width;
	int			height;

	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	while (!glfwWindowShouldClose(window))
	{
		if (!g_game.pause)
		{
			draw_bar();
			update_map(ft_strjoin("levels/level",
						ft_strjoin(ft_itoa(g_game.level), ".txt")));
			draw_ball();
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
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
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
