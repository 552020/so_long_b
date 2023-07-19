

#include "../include/so_long.h"

/* 
mlx_is_key_down: polling approach;
mlx_key_hook: event-driven approach;
TODO: actually the mlx_is_key_down should be declared outside of the hook. 

*/



void	move_hook(mlx_key_data_t keydata, void *tmp)
{
	t_game	*game;

	game = (t_game *) tmp;
	// if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		// mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(game, 'w');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(game, 's');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(game, 'd');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(game, 'a');
}

void	move_player(t_game *game, char dir)
{
	if (dir == 'w')
		move_up(game);
	if (dir == 's')
		move_down(game);
	if (dir == 'd')
		move_right(game);
	if (dir == 'a')
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
