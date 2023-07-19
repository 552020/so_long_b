#include "../include/so_long.h"

void	move_hook(mlx_key_data_t keydata, void *tmp)
{
	t_game	*game;

	game = (t_game *) tmp;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(game);
}


void	pick_collectibles(t_game *game, int y, int x)
{
	size_t	collectible_i;

	collectible_i = 0;
	x = x * PIXELS + 16;
	y = y * PIXELS + 16;
	while (collectible_i < game->img->collectible->count)
	{
		if (game->img->collectible->instances[collectible_i].x == x
			&& game->img->collectible->instances[collectible_i].y == y)
		{
			game->img->collectible->instances[collectible_i].enabled = false;
		}
		collectible_i++;
	}
}
