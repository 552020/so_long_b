
#include "../include/so_long.h"

char	*read_map(char *map)
{
	char	*line;
	char	*map_str;
	char	*tmp;
	int		fd;

	fd = open(map, O_RDONLY);
	map_str = ft_calloc(1, 1);
	if (!map_str)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			tmp = ft_strjoin(map_str, line);
			free(map_str);
			map_str = tmp;
			free (line);
		}
		else
			break ;
	}
	close (fd);
	return (map_str);
}

// gets x and y coordinates of player and exit
size_t	get_position(t_game *game, char axis, char obj)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map_grid[y][x] == obj)
			{
				if (axis == 'x')
					return (x);
				else
					return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}