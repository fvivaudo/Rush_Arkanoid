/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchauvie <cchauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 14:38:00 by cchauvie          #+#    #+#             */
/*   Updated: 2015/05/03 22:53:09 by cchauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <fcntl.h>
#include <unistd.h>

static char	**get_map(char *name)
{
	char		**map;
	char		*buf;
	int			fd;
	int			y;

	if (!(map = (char **)malloc(sizeof(char *) * (MAP_HEIGHT + 1))))
		ft_do_error("Malloc");
	y = 0;
	if ((fd = open(name, O_RDONLY)) == (-1))
		ft_do_error("Can't open Map file !");
	while (get_next_line(fd, &buf))
	{
		map[y++] = ft_strdup(buf);
		ft_putendl(map[y - 1]);
		free(buf);
	}
	map[y] = NULL;
	close(fd);
	return (map);
}

static char	**build_map(char **tmp_map)
{
	int			i;
	int			y;
	int			z;

	y = 0;
	while (tmp_map[y])
	{
		z = 0;
		i = 0;
		while (tmp_map[y][z])
		{
			if (ft_isdigit(tmp_map[y][z]))
			{
				g_game.map[y][i] = ft_atoi(tmp_map[y] + z);
				if (g_game.map[y][i] != 4)
					g_game.target_score += g_game.map[y][i];
			}
			while (ft_isdigit(tmp_map[y][z]))
				++z;
			++i;
			++z;
		}
		++y;
	}
	return (tmp_map);
}

void		update_map(char *name)
{
	static char	**tmp_map = NULL;
	int			i;
	int			y;

	if (!g_game.start_level)
	{
		tmp_map = build_map(get_map(name));
		g_game.start_level = 1;
	}
	i = 0;
	y = 0;
	while (i < MAP_HEIGHT)
	{
		while (y < MAP_WIDTH)
		{
			if (g_game.map[i][y] != 0)
				draw_brick(i, y, g_game.map[i][y]);
			++y;
		}
		y = 0;
		++i;
	}
}
