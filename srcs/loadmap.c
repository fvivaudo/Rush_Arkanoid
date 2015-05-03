/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:33:36 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/03 22:47:37 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <fcntl.h>
#include <unistd.h>

void		g_var_reset(void)
{
	g_game.start_level = 0;
	g_game.start = 0;
	g_game.life = 3;
	g_game.x = -0.93;
	g_game.x_dir = 0.01;
	g_game.y = 0;
	g_game.y_dir = 0;
}

void		g_var_init(void)
{
	int		i;

	i = 0;
	ft_bzero(&g_game, sizeof(t_game));
	g_var_reset();
	if (!(g_game.map = (int **)malloc(sizeof(int *) * MAP_HEIGHT)))
		ft_do_error("Malloc");
	while (i < MAP_HEIGHT)
		if (!(g_game.map[i++] = (int *)malloc(sizeof(int) * MAP_WIDTH)))
			ft_do_error("Malloc");
}

static void	check_map_file_content(int file_fd)
{
	char	*file_buffer;
	int		file_lines;
	size_t	index;

	file_lines = 0;
	while (get_next_line(file_fd, &file_buffer))
	{
		index = -1;
		while (index++ < ft_strlen(file_buffer))
		{
			if (file_buffer[index] != ' '
					|| file_buffer[index] < 0 || file_buffer[index] > 4)
				ft_do_error("Map file content text not correct !");
		}
		if (ft_strlen(file_buffer) != (MAP_WIDTH * 2) - 1)
			ft_do_error("Map file content widt not correct !");
		file_lines++;
		free(file_buffer);
	}
	if (file_lines != MAP_HEIGHT)
		ft_do_error("Map file content height not correct !");
}

void		check_map_file(char *filename)
{
	int		file_fd;

	if ((file_fd = open(filename, O_RDONLY)) == (-1))
	{
		if (g_game.level > 0)
		{
			print_text(-0.08, 0, "YOU WIN !!", 1);
			draw_infos();
			g_game.win = 1;
			return ;
		}
		else
			ft_do_error("Can't open Map file !");
	}
	check_map_file_content(file_fd);
	close(file_fd);
}
