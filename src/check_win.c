#include "so_long.h"

void	check_win(t_game *game)
{
	if (game->collected == game->collectibles)
	{
		if (mlx_image_to_window(game->mlx, game->img->exit_open,
				game->exit_x * PIXELS, game->exit_y * PIXELS) < 0)
			exit_with_error("Error while loading an image!", false);
		else
			game->img->exit_closed->instances[0].enabled = false;
		game->map_grid[game->exit_y][game->exit_x] = '0';
		if (game->player_x == game->exit_x && game->player_y == game->exit_y)
		{
			sleep(1);
			mlx_close_window(game->mlx);
			ft_putendl_fd("Congratulations, you won!", 1);
		}
	}
}