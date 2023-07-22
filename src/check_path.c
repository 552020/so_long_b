#include "so_long.h"


void	check_path(t_game *game)
{
	t_game	tmp;
	size_t	i;

	tmp.height = game->height;
	tmp.width = game->width;
	tmp.collectibles = game->collectibles;
	tmp.player_x = game->player_x;
	tmp.player_y = game->player_y;
	tmp.map_grid = (char **)malloc(sizeof(char *) * tmp.height);
	if (!tmp.map_grid)
		exit_with_error("Memory allocation problem", true);
	i = 0;
	while (i < tmp.height)
	{
		tmp.map_grid[i] = ft_strdup(game->map_grid[i]);
		i++;
	}
	flood_fill(&tmp, tmp.player_y, tmp.player_x);
	if (!(tmp.map_grid[game->exit_y][game->exit_x] == 'F' && tmp.collectibles == 0))
		exit_with_error("Path error! The exit is not reachable by the player!", false);
	free_grid(tmp.map_grid, tmp.height);
}

int	flood_fill(t_game *tmp, size_t y, size_t x)
{
	if (tmp->map_grid[y][x] == '1')
		return (0);
	if (tmp->map_grid[y][x] == 'F')
		return (0);
	if (tmp->map_grid[y][x] == 'C')
		tmp->collectibles--;
	tmp->map_grid[y][x] = 'F';
	if (flood_fill(tmp, y + 1, x))
		return (1);
	if (flood_fill(tmp, y - 1, x))
		return (1);
	if (flood_fill(tmp, y, x + 1))
		return (1);
	if (flood_fill(tmp, y, x - 1))
		return (1);
	return (0);
}

void	free_grid(char **grid, size_t grid_height)
{
	size_t	i;

	i = 0;
	while (i < grid_height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
