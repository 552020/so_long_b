#include "../include/so_long.h"

void exit_with_error(const char *msg, bool is_system_error)
{
	if (is_system_error)
		perror(msg);
	else
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd((char *)msg, 2);
	}
	exit(1);
}

void	free_game(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map_grid[i]);
		i++;
	}
	free(game->map_grid);
	free(game->img);
	free(game);
}
