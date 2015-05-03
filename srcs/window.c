/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 19:20:33 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/03 22:48:29 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>
#include <GLUT/glut.h>

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
		else if (key == GLFW_KEY_ENTER)
			g_game.start = 1;
		else if (!g_game.pause
				&& key == GLFW_KEY_RIGHT && g_game.bar_position + 0.1 <= 1.0)
			g_game.bar_position += 0.03;
		else if (!g_game.pause &&
				key == GLFW_KEY_LEFT && g_game.bar_position - 0.1 >= -1.0)
			g_game.bar_position -= 0.03;
	}
}

void		print_text(float x, float y, char *str, bool big)
{
	size_t		index;
	void		*police;

	index = 0;
	glColor3f(1.f, 0.f, 0.f);
	glRasterPos2f(x, y);
	if (big)
		police = GLUT_BITMAP_TIMES_ROMAN_24;
	else
		police = GLUT_BITMAP_HELVETICA_18;
	while (index < ft_strlen(str))
		glutBitmapCharacter(police, str[index++]);
}

static void	run_game(GLFWwindow *window)
{
	while (!glfwWindowShouldClose(window))
	{
		if (!g_game.win && !g_game.pause)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			update_map(ft_strjoin("levels/level",
						ft_strjoin(ft_itoa(g_game.level), ".txt")));
			draw_infos();
			draw_bar();
			draw_ball();
			if (!g_game.start)
				print_text(-0.2, -0.2, "Press start to continue ...", 0);
			if (g_game.target_score == 0)
			{
				g_game.level++;
				g_var_reset();
				check_map_file(ft_strjoin("levels/level",
							ft_strjoin(ft_itoa(g_game.level), ".txt")));
			}
		}
		else if (!g_game.win)
			print_text(-0.08, 0, "PAUSED", 1);
		glfwSwapBuffers(window);
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
