/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:37:48 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/03 15:51:42 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <fcntl.h>
#include <unistd.h>

static void	g_var_init(void)
{
	int		i;

	i = 0;
	ft_bzero(&g_game, sizeof(t_game));
	g_game.speed = 1.3;
	g_game.x = -0.95;
	g_game.x_dir = 0.01;
	g_game.y_dir = 0.01;
	if (!(g_game.map = (int **)malloc(sizeof(int *) * MAP_HEIGHT)))
		ft_do_error("Malloc");
	while (i < MAP_HEIGHT)
		if (!(g_game.map[i++] = (int *)malloc(sizeof(int) * MAP_WIDTH)))
			ft_do_error("Malloc");
}

static void	print_game_cmd(void)
{
	ft_printf("=============================\n\
Game Commands :\n\
- ESC : Exit game\n\
- Space : Pause\n\
- Left Arrow : Go left\n\
- Right Arrow : Go right\n\
=============================\n");
}

static void	check_map_file(char *filename)
{
	int		file_fd;
	int		file_lines;
	char	*file_buffer;

	if ((file_fd = open(filename, O_RDONLY)) == (-1))
		ft_do_error("Can't open Map file !");
	file_lines = 0;
	while (get_next_line(file_fd, &file_buffer))
	{
		if (ft_strlen(file_buffer) != (MAP_WIDTH * 2) - 1)
			ft_do_error("Map file content widt not correct !");
		file_lines++;
		free(file_buffer);
	}
	if (file_lines != MAP_HEIGHT)
		ft_do_error("Map file content height not correct !");
	close(file_fd);
}

void		ft_do_error(char *str)
{
	ft_dprintf(2, "ERROR : %s\n", str);
	exit(EXIT_FAILURE);
}

int			main(void)
{
	check_map_file("levels/level0.txt");
	g_var_init();
	print_game_cmd();
	return (init_game());
}
